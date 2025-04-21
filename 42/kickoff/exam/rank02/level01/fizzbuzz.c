#include <unistd.h>

int	is_odd(int n)
{
	return (n % 2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	main(void)
{
	int	n;

	n = -1;
	while (++n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(n);
		ft_putchar('\n');
	}
	return (0);
}
