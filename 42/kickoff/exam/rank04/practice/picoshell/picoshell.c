#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int picoshell(char **cmds[]) {
	int pfd[2];
	pid_t pid;
	int prev_fd = -1;
	int has_error = 0;
	int i;

	i = -1;
	while (cmds[++i] && !has_error) {
		int need_pipe = (cmds[i + 1] != 0);
		if (need_pipe && pipe(pfd) == -1) {
			has_error = 1;
			break;
		}
		pid = fork();
		if (pid == -1) {
			if (need_pipe) {
				close(pfd[0]);
				close(pfd[1]);
			}
			has_error = 1;
			break;
		}
		if (pid == 0) {
			if (prev_fd != -1) {
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}
			if (need_pipe) {
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
		if (need_pipe) {
			close(pfd[1]);
			prev_fd = pfd[0];
		} else {
			prev_fd = -1;
		}
	}

	if (prev_fd != -1)
		close(prev_fd);
	while(wait(NULL) != -1) {}
	return has_error ? 1 : 0;
}
