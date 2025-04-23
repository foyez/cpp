/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:39:21 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 01:42:08 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*ft_init_flags(t_flags *flags)
{
	flags->left_align = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->precision_set = 0;
	flags->zero_pad = 0;
	flags->plus_sign = 0;
	flags->space = 0;
	flags->alt_form = 0;
	return (flags);
}

static const char	*ft_parse_num(const char *format, int *num)
{
	*num = 0;
	while (*format >= '0' && *format <= '9')
	{
		*num = *num * 10 + (*format - '0');
		format++;
	}
	return (format);
}

static t_flags	ft_left_align(t_flags flags)
{
	flags.left_align = 1;
	flags.zero_pad = 0;
	return (flags);
}

static t_flags	ft_plus_sign(t_flags flags)
{
	flags.plus_sign = 1;
	flags.space = 0;
	return (flags);
}

const char	*parse_flags(const char *fmt, t_flags *flags)
{
	ft_init_flags(flags);
	while (*fmt == '-' || *fmt == '0' || *fmt == '+' || *fmt == ' '
		|| *fmt == '#')
	{
		if (*fmt == '-')
			*flags = ft_left_align(*flags);
		if (*fmt == '0' && !flags->left_align)
			flags->zero_pad = 1;
		if (*fmt == '+')
			*flags = ft_plus_sign(*flags);
		if (*fmt == ' ' && !flags->plus_sign)
			flags->space = 1;
		if (*fmt == '#')
			flags->alt_form = 1;
		fmt++;
	}
	fmt = ft_parse_num(fmt, &flags->width);
	if (*fmt == '.')
	{
		fmt++;
		flags->precision_set = 1;
		flags->precision = 0;
		flags->zero_pad = 0;
		fmt = ft_parse_num(fmt, &flags->precision);
	}
	return (fmt);
}
