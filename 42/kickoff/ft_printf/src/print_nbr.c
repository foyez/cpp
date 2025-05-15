/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:14:48 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/15 00:50:06 by kaahmed          ###   ########.fr       */
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

static int	ft_put_sign(int fd, int is_negative, t_flags flags)
{
	if (is_negative)
		return (ft_putchar(fd, '-'));
	if (flags.plus_sign)
		return (ft_putchar(fd, '+'));
	else if (flags.space)
		return (ft_putchar(fd, ' '));
	return (0);
}

static int	ft_put_left_align(t_flags f, t_vars *v, char *buf, int is_neg)
{
	if (f.zero_pad || f.left_align)
	{
		v->ret = ft_put_sign(v->fd, is_neg, f);
		if (!safe_count(v->ret, &v->count))
			return (-1);
	}
	if (f.left_align)
	{
		v->ret = ft_putbuf(v->fd, buf, v->len, v->zeros);
		if (!safe_count(v->ret, &v->count))
			return (-1);
	}
	return (0);
}

static int	ft_putnbr_content(t_flags f, t_vars v, char *buf, int is_neg)
{
	v.ret = ft_put_left_align(f, &v, buf, is_neg);
	if (v.ret == -1)
		return (-1);
	v.ret = ft_putpad(v.fd, f.width, v.contentlen, f.zero_pad);
	if (!safe_count(v.ret, &v.count))
		return (-1);
	if (!f.zero_pad && !f.left_align)
	{
		v.ret = ft_put_sign(v.fd, is_neg, f);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	if (!f.left_align)
	{
		v.ret = ft_putbuf(v.fd, buf, v.len, v.zeros);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	return (v.count);
}

// Effect: -, 0, ., +, and space
// No effect: #
int	print_nbr(int fd, int n, t_flags flags)
{
	t_vars	vars;
	char	buf[16];
	int		is_negative;
	int		extra_char;

	vars.fd = fd;
	vars.count = 0;
	is_negative = n < 0;
	vars.len = ft_itoa_base10(n, buf);
	vars.zeros = 0;
	vars.ret = 0;
	if (flags.precision == 0 && n == 0)
		vars.len = 0;
	extra_char = 0;
	if (is_negative || flags.plus_sign || flags.space)
		extra_char = 1;
	if (flags.precision_set && flags.precision > vars.len)
		vars.zeros = flags.precision - vars.len;
	vars.contentlen = vars.len + vars.zeros + extra_char;
	vars.count = ft_putnbr_content(flags, vars, buf, is_negative);
	return (vars.count);
}
