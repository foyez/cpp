/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:10:06 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 20:22:34 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str, t_flags flags)
{
	t_vars v;

	v.count = 0;
	if (!str)
		str = "(null)";
	v.len = ft_strlen(str);
	v.contentlen = v.len;
	if (flags.precision_set && flags.precision < v.contentlen)
		v.contentlen = flags.precision;
	if (flags.left_align)
	{
		v.ret = ft_putnstr(str, v.contentlen);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	v.ret = ft_putpad(flags.width, v.contentlen, 0);
	if (!safe_count(v.ret, &v.count))
		return (-1);
	if (!flags.left_align)
	{
		v.ret = ft_putnstr(str, v.contentlen);
		if (!safe_count(v.ret, &v.count))
			return (-1);
	}
	return (v.count);
}
