#include <unistd.h>
#include <stdlib.h>

int ft_popen(char *file, char *const argv[], char type) {
	int pfd[2];
	pid_t pid;
	int ret;

	if (!file || !argv || !(type == 'r' || type == 'w'))
		return -1;

	if (pipe(pfd) < 0)
		return -1;

	pid = fork();
	if (pid == -1) {
		close(pfd[0]);
		close(pfd[1]);
		return -1;
	}

	if (pid == 0) {
		if (type == 'r') {
			if (dup2(pfd[1], STDOUT_FILENO) == -1)
				exit(1);
		} else {
			if (dup2(pfd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(pfd[0]);
		close(pfd[1]);

		execvp(file, argv);
		exit(1);
	}

	ret = -1;
	if (type == 'r') {
		close(pfd[1]);
		ret = pfd[0];
	} else {
		close(pfd[0]);
		ret = pfd[1];
	}
	return ret;
}

#include <stdio.h>

int main()
{
	int fd;
	char buffer[1024];
	ssize_t bytes;

	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	if (fd == -1)
		return 1;

	while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
		buffer[bytes] = '\0';
		printf("%s", buffer);
	}
	close(fd);
	return 0;
}

// int main()
// {
// 	int fd;
//
// 	fd = ft_popen("wc", (char *const []){"wc", "-l", NULL}, 'w');
// 	if (fd == -1)
// 		return 1;
//
// 	write(fd, "line 1\n", 7);
// 	write(fd, "line 2\n", 7);
// 	write(fd, "line 3\n", 7);
//
// 	close(fd);
// 	return 0;
// }
