#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int picoshell(char **cmds[]);

int main(void)
{
	char *cmd1[] = {"ls1", "-l", NULL};
	char *cmd2[] = {"grep", ".c", NULL};
	// char *cmd3[] = {"wc", "-l", NULL};

	char **cmds[] = {cmd1, cmd2, NULL};

	int rc = picoshell(cmds);
	printf("status %d\n", rc);
	return 0;
}
