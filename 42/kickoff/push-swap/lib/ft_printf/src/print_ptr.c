/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:11:40 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/25 01:17:43 by kaahmed          ###   ########.fr       */
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
	t_vars	vars;
	char	hex_buf[32];

	vars.count = 0;
	vars.ret = 0;
	vars.len = ft_utoa_ptr(ptr, hex_buf);
	vars.contentlen = 2 + vars.len;
	if (flags.left_align)
	{
		vars.ret = ft_putptr(hex_buf, vars.len);
		if (!safe_count(vars.ret, &vars.count))
			return (-1);
	}
	vars.ret = ft_putpad(flags.width, vars.contentlen, 0);
	if (!safe_count(vars.ret, &vars.count))
		return (-1);
	if (!flags.left_align)
	{
		vars.ret = ft_putptr(hex_buf, vars.len);
		if (!safe_count(vars.ret, &vars.count))
			return (-1);
	}
	return (vars.count);
}
