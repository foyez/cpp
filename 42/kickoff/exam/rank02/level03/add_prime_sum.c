#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 1;
	while (++i <= n / 2)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

void	add_prime_sum(int n)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (n > 1)
	{
		if (is_prime(n))
			res += n;
		n--;
	}
	ft_putnbr(res);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) <= 0)
		write(1, "0\n", 2);
	else
	{
		add_prime_sum(ft_atoi(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
