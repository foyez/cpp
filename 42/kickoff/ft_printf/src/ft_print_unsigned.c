/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:01:12 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/25 17:26:49 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

static int	ft_put_nbr_content(unsigned int n, t_flags flags)
{
	char	*num;
	int		len;
	int		num_len;

	len = 0;
	num_len = ft_nbrlen(n);
	while (num_len < flags.precision)
	{
		len += ft_putchar('0');
		flags.precision--;
	}
	if (!(n == 0 && flags.precision == 0))
	{
		num = ft_uitoa(n);
		if (!num)
			return (0);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}

// Effect: -, 0, .
// No effect: +, # and space
int	ft_print_unsigned(unsigned int n, t_flags flags)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(n);
	if (flags.precision > num_len)
		num_len = flags.precision;
	else if (n == 0 && flags.precision == 0)
		num_len = 0;
	if (flags.left_align)
		len += ft_put_nbr_content(n, flags);
	len += ft_pad_width(flags.width, num_len, flags.zero_pad);
	if (!flags.left_align)
		len += ft_put_nbr_content(n, flags);
	return (len);
}
