/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:53 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/26 12:27:51 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;
	int		ret;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			format = ft_parse_flags(format, &flags);
			ret = ft_handle_format(*format, &args, flags);
		}
		else
			ret = ft_putchar(*format);
		if (ret == -1)
			return (ft_error(args));
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
