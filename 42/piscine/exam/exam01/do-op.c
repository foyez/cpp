#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int	ascii_to_num(char ascii)
{
	return (ascii - '0');
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			res;
	const int	space = 32;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == space || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += ascii_to_num(str[i]);
		i++;
	}
	return (res * sign);
}

int	main(int argc, char **argv)
{
	char	*n1;
	char	*n2;
	char	*op;
	int		res;

	if (argc == 4)
	{
		n1 = argv[1];
		n2 = argv[3];
		op = argv[2];
		if (*op == '+')
		{
			res = ft_atoi(n1) + ft_atoi(n2);
		}
		else if (*op == '-')
		{
			res = ft_atoi(n1) - ft_atoi(n2);
		}
		else if (*op == '*')
		{
			res = ft_atoi(n1) * ft_atoi(n2);
		}
		else if (*op == '/')
		{
			res = ft_atoi(n1) / ft_atoi(n2);
		}
		else if (*op == '%')
		{
			res = ft_atoi(n1) % ft_atoi(n2);
		}
		ft_putnbr(res);
	}
	ft_putchar('\n');
	return (0);
}
