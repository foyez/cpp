/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:05:38 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/03 21:50:52 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_len(char *base);
int		handle_sign(char *str, int *i);

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

int	ft_nbr_len(long nbr, int base_len)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
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
	long	result;
	int		sign;
	int		base_len;
	int		i;
	int		base_val;

	result = 0;
	base_len = ft_base_len(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	sign = handle_sign(str, &i);
	while (str[i] != '\0')
	{
		base_val = get_base_value(str[i], base);
		if (base_val == -1)
			break ;
		result = result * base_len + base_val;
		i++;
	}
	return (sign * (int)result);
}

long	handle_negative(char *str, long n)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -(n);
	}
	return (n);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	n;
	int		base_len;
	int		len;
	char	*str;

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
	n = handle_negative(str, n);
	while (n > 0)
	{
		str[len--] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
