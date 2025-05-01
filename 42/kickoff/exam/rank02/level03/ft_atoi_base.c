int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	get_base_val(int c, int base)
{
	char	*lcbase;
	char	*upbase;
	int		i;

	i = 0;
	lcbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	while (lcbase[i] == c || upbase[i] == c)
	{
		return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	res;
	int	sign;
	int	val;

	res = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = -1;
	while (*str)
	{
		val = get_base_val(*str, base);
		if (val == -1)
			break ;
		res = res * base + val;
		str++;
	}
	return (res * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("10", 16));
	return (0);
}
