#include <unistd.h>
#include <stdlib.h>

int ft_popen(char *file, char *const argv[], char type)
{
	int pfd[2];
	pid_t pid;
	int ret;

	ret = -1;
	if (!file || !argv || !(type == 'r' || type == 'w'))
		return -1;
	if (pipe(pfd) < 0)
		return -1;
	pid = fork();
	if (pid < 0) {
		close(pfd[0]);
		close(pfd[1]);
		return -1;
	}
	if (pid == 0) {
		if (type == 'r') {
			if (dup2(pfd[1], STDOUT_FILENO) < 0)
				exit(1);
		}
		else if (type == 'w') {
			if (dup2(pfd[0], STDIN_FILENO) < 0)
				exit(1);
		}
		close(pfd[0]);
		close(pfd[1]);

		execvp(file, argv);
		exit(1);
	}
	if (type == 'r') {
		close(pfd[1]);
		ret = pfd[0];
	}
	else {
		close(pfd[0]);
		ret = pfd[1];
	}
	return ret;
}

#include <stdio.h>

// int main()
// {
// 	int fd;
// 	char buf[1024];
// 	ssize_t bytes;
//
// 	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
// 	if (fd == -1)
// 		return 1;
// 	while ((bytes = read(fd, buf, sizeof(buf) - 1)) > 0)
// 	{
// 		buf[bytes] = '\0';
// 		printf("%s", buf);
// 	}
// 	close(fd);
// 	return 0;
// }

int main()
{
	int fd;

	fd = ft_popen("wc", (char *const []){"wc", "-l", NULL}, 'w');
	if (fd == -1)
		return 1;
	write(fd, "line 1\n", 7);

	close(fd);
	return 0;
}

// gcc -Wall -Wextra -Werror -g ft_popen.c
// valgrind --leak-check=full --track-fds=yes ./a.out
