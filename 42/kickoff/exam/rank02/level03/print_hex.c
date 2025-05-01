#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int ft_atoi(char *s)
{
	unsigned int res = 0;
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}

void ft_puthex(int n)
{
	char *base = "0123456789abcdef";

	if (n > 15)
		ft_puthex(n / 16);
	ft_putchar(base[n % 16]);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_puthex(ft_atoi(argv[1]));
	}
	ft_putchar('\n');
	return (0);
}
