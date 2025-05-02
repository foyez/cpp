#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		char *n1 = argv[1];
		char *op = argv[2];
		char *n2 = argv[3];

		if (*op == '+')
			printf("%d", atoi(n1) + atoi(n2));
		else if (*op == '-')
			printf("%d", atoi(n1) - atoi(n2));
		else if (*op == '*')
			printf("%d", atoi(n1) * atoi(n2));
		else if (*op == '/')
			printf("%d", atoi(n1) / atoi(n2));
		else if (*op == '%')
			printf("%d", atoi(n1) % atoi(n2));
	}
	printf("\n");
	return (0);
}
