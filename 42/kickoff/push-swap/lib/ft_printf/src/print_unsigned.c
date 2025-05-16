/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:54:42 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/25 00:56:47 by kaahmed          ###   ########.fr       */
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

void	init_vars(t_vars *v, t_flags *f, unsigned int n, char *buf)
{
	v->count = 0;
	v->len = ft_utoa(n, buf);
	v->ret = 0;
	v->zeros = 0;
	if (f->precision == 0 && n == 0)
		v->len = 0;
	if (f->precision_set && f->precision > v->len)
		v->zeros = f->precision - v->len;
}

int	print_unsigned(unsigned int n, t_flags flags)
{
	t_vars	vars;
	char	buf[16];

	init_vars(&vars, &flags, n, buf);
	if (!flags.left_align)
	{
		vars.ret = ft_putpad(flags.width, vars.len + vars.zeros,
				flags.zero_pad);
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
