/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:54:42 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 21:27:17 by kaahmed          ###   ########.fr       */
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
	t_vars vars;
	char	buf[16];

	vars.count = 0;
	vars.len = ft_utoa(n, buf);
	vars.ret = 0;
	vars.zeros = 0;
	if (flags.precision == 0 && n == 0)
		vars.len = 0;
	if (flags.precision_set && flags.precision > vars.len)
		vars.zeros = flags.precision - vars.len;
	if (!flags.left_align)
	{
		vars.ret = ft_putpad(flags.width, vars.len + vars.zeros, flags.zero_pad);
		if (!safe_count(vars.ret, &vars.count))
			return (-1);
	}
	vars.ret = ft_putbuf(buf, vars.len, vars.zeros);
	if (!safe_count(vars.ret, &vars.count))
		return (-1);
	if (flags.left_align)
	{
		vars.ret = ft_putpad(flags.width, vars.len + vars.zeros, 0);
		if (!safe_count(vars.ret, &vars.count))
			return (-1);
	}
	return (vars.count);
}
