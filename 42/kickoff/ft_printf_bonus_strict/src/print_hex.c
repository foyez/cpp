/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:18:35 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:20:15 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_utoa_hex(unsigned int num, char *buf, int low)
{
	const char	*hex = "0123456789abcdef";
	int			i;
	int			rem;

	i = 0;
	if (num == 0)
	{
		buf[i++] = '0';
		return (i);
	}
	while (num)
	{
		rem = num % 16;
		if (rem > 9 && !low)
			buf[i++] = hex[rem] - 32;
		else
			buf[i++] = hex[rem];
		num /= 16;
	}
	return (i);
}

int	ft_putprefix(int low)
{
	int	ret;

	ret = 0;
	if (low)
		ret = write(1, "0x", 2);
	else
		ret = write(1, "0X", 2);
	if (ret != 2)
		return (-1);
	return (2);
}

// Effect: -, 0, ., and #
// No Effect: + and space
int	print_hex(unsigned int num, t_flags flags, int low)
{
	int		count;
	int		ret;
	char	hex_buf[16];
	int		hexlen;
	int		prefixlen;
	int		zeros;
	int		contentlen;

	count = 0;
	ret = 0;
	hexlen = ft_utoa_hex(num, hex_buf, low);
	prefixlen = 0;
	zeros = 0;
	if (flags.precision == 0 && num == 0)
		hexlen = 0;
	if (flags.alt_form && num != 0)
		prefixlen = 2;
	if (flags.precision_set && flags.precision > hexlen)
		zeros = flags.precision - hexlen;
	contentlen = prefixlen + zeros + hexlen;
	if (prefixlen > 0 && (flags.zero_pad || flags.left_align))
	{
		ret = ft_putprefix(low);
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
		ret = ft_putbuf(hex_buf, hexlen);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putpad(flags.width, contentlen, flags.zero_pad);
	if (ret == -1)
		return (-1);
	count += ret;
	if (prefixlen > 0 && !flags.zero_pad && !flags.left_align)
	{
		ret = ft_putprefix(low);
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
		ret = ft_putbuf(hex_buf, hexlen);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}
