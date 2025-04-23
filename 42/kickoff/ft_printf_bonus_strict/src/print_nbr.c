/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:14:48 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:17:18 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoa_base10(int n, char *buf)
{
	unsigned int	num;
	int				i;

	i = 0;
	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)n;
	if (num == 0)
		buf[i++] = '0';
	while (num)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	return (i);
}

static int	ft_put_sign(int is_negative, t_flags flags)
{
	if (is_negative)
		return (ft_putchar('-'));
	if (flags.plus_sign)
		return (ft_putchar('+'));
	else if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

// Effect: -, 0, ., +, and space
// No effect: #
int	print_nbr(int n, t_flags flags)
{
	int		count;
	char	buf[16];
	int		is_negative;
	int		len;
	int		zeros;
	int		ret;
	int		extra_char;

	count = 0;
	is_negative = n < 0;
	len = ft_itoa_base10(n, buf);
	zeros = 0;
	ret = 0;
	if (flags.precision == 0 && n == 0)
		len = 0;
	extra_char = 0;
	if (is_negative || flags.plus_sign || flags.space)
		extra_char = 1;
	if (flags.precision_set && flags.precision > len)
		zeros = flags.precision - len;
	int contentlen = len + zeros + extra_char;
	if (flags.zero_pad || flags.left_align)
	{
		ret = ft_put_sign(is_negative, flags);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (flags.left_align)
	{
		if (zeros > 0)
		{
			ret = ft_putnchar('0', zeros);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		ret = ft_putbuf(buf, len);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putpad(flags.width, contentlen, flags.zero_pad);
	if (ret == -1)
		return (-1);
	count += ret;
	if (!flags.zero_pad && !flags.left_align)
	{
		ret = ft_put_sign(is_negative, flags);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (!flags.left_align)
	{
		if (zeros > 0)
		{
			ret = ft_putnchar('0', zeros);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		ret = ft_putbuf(buf, len);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}
