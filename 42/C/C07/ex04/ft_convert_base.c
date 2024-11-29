#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);

int	is_special_chars(char c)
{
	return (c <= 32 || c == 127 || c == '-' || c == '+');
}

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (is_special_chars(base[i]))
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;

	if (ft_base_len(base_from) == 0 || ft_base_len(base_to) == 0)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(num, base_to));
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_convert_base("42", "0123456789", "01"));
	printf("%s\n", ft_convert_base("-42", "0123456789", "0123456789ABCDEF"));
	return (0);
}
