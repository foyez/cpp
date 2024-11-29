#include <stdlib.h>

int		ft_base_len(char *base);

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

int	ft_nbr_len(int nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	i;
	int	base_val;

	result = 0;
	sign = 1;
	base_len = ft_base_len(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		base_val = get_base_value(str[i], base);
		if (base_val == -1)
			return (0);
		result = result * base_len + base_val;
		i++;
	}
	return (sign * result);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long n;
	int base_len;
	int len;
	char *str;

	n = nbr;
	base_len = ft_base_len(base);
	len = ft_nbr_len(nbr, base_len);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = base[0];
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len--] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
