// #include <stdio.h>
//
int picoshell(char **cmds[]);
//
// int main()
// {
// 	char *cmd1[] = { "ls", "-l", NULL };
// 	char *cmd2[] = { "grep", ".c", NULL };
// 	char *cmd3[] = { "wc", "-l", NULL };
//
// 	char **cmds[] = { cmd1, cmd2, cmd3 };
//
// 	int rc = picoshell(cmds);
// 	printf("status: %d\n", rc);
// 	return rc;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int count_cmds(int argc, char **argv)
{
		int count = 1;
		for (int i = 1; i < argc; i++)
		{
				if (strcmp(argv[i], "|") == 0)
						count++;
		}
		return count;
}

int main(int argc, char **argv)
{
		if (argc < 2)
				return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

		int cmd_count = count_cmds(argc, argv);
		char ***cmds = calloc(cmd_count + 1, sizeof(char **));
		if (!cmds)
				return (perror("calloc"), 1);

		// Parsear argumentos y construir array de comandos
		int i = 1, j = 0;
		while (i < argc)
		{
				int len = 0;
				while (i + len < argc && strcmp(argv[i + len], "|") != 0)
						len++;
				
				cmds[j] = calloc(len + 1, sizeof(char *));
				if (!cmds[j])
						return (perror("calloc"), 1);
				
				for (int k = 0; k < len; k++)
						cmds[j][k] = argv[i + k];
				cmds[j][len] = NULL;
				
				i += len + 1;  // Saltar el "|"
				j++;
		}
		cmds[cmd_count] = NULL;

		int ret = picoshell(cmds);

		// Limpiar memoria
		for (int i = 0; cmds[i]; i++)
				free(cmds[i]);
		free(cmds);
		
		printf("count: %d\n", cmd_count);

		return ret;
}
