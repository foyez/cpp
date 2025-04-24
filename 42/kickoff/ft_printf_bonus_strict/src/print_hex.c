/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:18:35 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/25 01:30:46 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_utoa_hex(unsigned int num, char *buf, int low)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	if (!low)
		hex = "0123456789ABCDEF";
	i = 0;
	if (num == 0)
		buf[i++] = '0';
	while (num)
	{
		buf[i++] = hex[num % 16];
		num /= 16;
	}
	return (i);
}

static int	ft_putprefix_if(int prefixlen, int low)
{
	int		ret;
	char	*prefix_str;

	if (prefixlen == 0)
		return (0);
	prefix_str = "0x";
	if (!low)
		prefix_str = "0X";
	ret = ft_putnstr(prefix_str, prefixlen);
	if (ret != 2)
		return (-1);
	return (ret);
}

static int	ft_put_left_align(t_flags f, t_vars *v, char *buf, t_hex_args args)
{
	if (f.zero_pad || f.left_align)
	{
		v->ret = ft_putprefix_if(args.prefixlen, args.low);
		if (!safe_count(v->ret, &v->count))
			return (-1);
	}
	if (f.left_align)
	{
		v->ret = ft_putbuf(buf, v->len, v->zeros);
		if (!safe_count(v->ret, &v->count))
			return (-1);
	}
	return (0);
}

static int	ft_puthex(t_flags f, t_vars v, char *buf, t_hex_args args)
{
	v.ret = ft_put_left_align(f, &v, buf, args);
	if (v.ret == -1)
		return (-1);
	v.ret = ft_putpad(f.width, v.contentlen, f.zero_pad);
	if (!safe_count(v.ret, &v.count))
		return (-1);
	if (!f.zero_pad && !f.left_align)
	{
		v.ret = ft_putprefix_if(args.prefixlen, args.low);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	if (!f.left_align)
	{
		v.ret = ft_putbuf(buf, v.len, v.zeros);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	return (v.count);
}

// Effect: -, 0, ., and #
// No Effect: + and space
int	print_hex(unsigned int num, t_flags flags, int low)
{
	t_vars		vars;
	t_hex_args	args;
	char		buf[16];
	int			prefixlen;

	vars.count = 0;
	prefixlen = 0;
	vars.zeros = 0;
	vars.len = ft_utoa_hex(num, buf, low);
	if (flags.precision == 0 && num == 0)
		vars.len = 0;
	if (flags.alt_form && num != 0)
		prefixlen = 2;
	if (flags.precision_set && flags.precision > vars.len)
		vars.zeros = flags.precision - vars.len;
	vars.contentlen = prefixlen + vars.zeros + vars.len;
	args.low = low;
	args.prefixlen = prefixlen;
	vars.count = ft_puthex(flags, vars, buf, args);
	return (vars.count);
}
