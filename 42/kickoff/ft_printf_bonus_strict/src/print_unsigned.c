/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:54:42 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:21:01 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_utoa(unsigned int n, char *buf)
{
	int	i;

	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (i);
}

int	print_unsigned(unsigned int n, t_flags flags)
{
	int		count;
	char	buf[16];
	int		len;
	int		ret;
	int		zeros;
	int		i;

	count = 0;
	len = ft_utoa(n, buf);
	ret = 0;
	zeros = 0;
	if (flags.precision == 0 && n == 0)
		len = 0;
	if (flags.precision_set && flags.precision > len)
		zeros = flags.precision - len;
	if (!flags.left_align)
	{
		ret = ft_putpad(flags.width, len + zeros, flags.zero_pad);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (zeros > 0)
	{
		ret = ft_putnchar('0', zeros);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	i = len;
	while (--i >= 0)
	{
		if (ft_putchar(buf[i]) == -1)
			return (-1);
		count++;
	}
	if (flags.left_align)
	{
		ret = ft_putpad(flags.width, len + zeros, 0);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}
