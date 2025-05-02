#include <stdio.h>
#include <stdlib.h>

void fprime(int n)
{
	if (n == 1)
		printf("1");
	int i = 2;
	while (i <= n)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (n != i)
				printf("*");
			n /= i;
		}
		else
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return 0;
}
