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

int	get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;
	int	sign;
	int	result;
	int	i;
	int	base_value;

	baselen = ft_baselen(base);
	if (baselen <= 1)
		return (0);
	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		base_value = get_base_value(str[i], base);
		if (base_value == -1)
			return (0);
		result = result * baselen + base_value;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base(" ---+--+133742", "0123456789"));
	printf("%d\n", ft_atoi_base(" ---+--+101010", "01"));
	printf("%d\n", ft_atoi_base(" ---+--+1a", "0123456789abcdef"));
	return (0);
}
