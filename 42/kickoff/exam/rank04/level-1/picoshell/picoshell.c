#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int picoshell(char **cmds[]) {
	pid_t pid;
	int pfd[2];
	int prev_fd = -1;
	int wstatus;
	int rc = 0;
	int i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i + 1] && pipe(pfd) == -1)
			return 1;
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(pfd[0]);
				close(pfd[1]);
			}
			return 1;
		}

		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}

			if (cmds[i + 1])
			{
				close(pfd[0]);
				if (dup2(pfd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(pfd[1]);
			}

			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

		if (prev_fd != -1)
			close(prev_fd);

		if (cmds[i + 1])
		{
			close(pfd[1]);
			prev_fd = pfd[0];
		}
	}

	
	while (wait(&wstatus) != -1)
	{
			if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
					rc = 1;
	}

	return rc;
}

