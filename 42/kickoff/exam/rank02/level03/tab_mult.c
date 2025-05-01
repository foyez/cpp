#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
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

void tab_mult(int n)
{
	int i = 0;

	while (++i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		ft_putchar('\n');
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	else
		tab_mult(ft_atoi(argv[1]));
	return (0);
}
