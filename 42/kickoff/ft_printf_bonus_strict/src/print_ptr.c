/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:11:40 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 20:49:37 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_utoa_ptr(unsigned long num, char *buf)
{
	const char	*hex = "0123456789abcdef";
	int			i;

	i = 0;
	if (num == 0)
	{
		buf[i++] = '0';
		return (i);
	}
	while (num)
	{
		buf[i++] = hex[num % 16];
		num /= 16;
	}
	return (i);
}

int	ft_putptr(char *buf, int len)
{
	int	count;
	int	ret;

	count = 0;
	ret = write(1, "0x", 2);
	if (ret != 2)
		return (-1);
	count += ret;
	while (--len >= 0)
	{
		if (ft_putchar(buf[len]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	print_ptr(unsigned long ptr, t_flags flags)
{
	int		count;
	int		ret;
	char	hex_buf[32];
	int		hexlen;
	int		printlen;

	count = 0;
	ret = 0;
	hexlen = ft_utoa_ptr(ptr, hex_buf);
	printlen = 2 + hexlen;
	if (flags.left_align)
	{
		ret = ft_putptr(hex_buf, hexlen);
		if (!safe_count(ret, &count))
			return (-1);
	}
	ret = ft_putpad(flags.width, printlen, 0);
	if (!safe_count(ret, &count))
		return (-1);
	if (!flags.left_align)
	{
		ret = ft_putptr(hex_buf, hexlen);
		if (!safe_count(ret, &count))
			return (-1);
	}
	return (count);
}
