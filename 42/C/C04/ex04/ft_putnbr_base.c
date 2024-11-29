#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_special_char(char c)
{
	return (c <= 32 || c == 127 || c == '+' || c == '-');
}

int	ft_baselen(char *base)
{
	int	i;
	int	j;

	// if base len 0 or 1
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (ft_special_char(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baselen;
	long	n;

	n = nbr;
	baselen = ft_baselen(base);
	if (baselen <= 1)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= baselen)
	{
		ft_putnbr_base(n / baselen, base);
		ft_putnbr_base(n % baselen, base);
	}
	else
		ft_putchar(base[n]);
}

#include <stdio.h>

int	main(void)
{
	ft_putnbr_base(-42, "+01");
	printf("\n");
	ft_putnbr_base(-42, "01");
	printf("\n");
	ft_putnbr_base(40, "poneyvif");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
	return (0);
}
