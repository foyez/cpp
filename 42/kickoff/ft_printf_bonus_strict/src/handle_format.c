/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:39:36 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 01:55:52 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char c, va_list *args, t_flags flags)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int), flags));
	if (c == '%')
		return (print_char('%', flags));
	if (c == 's')
		return (print_str(va_arg(*args, char *), flags));
	if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(*args, int), flags));
	if (c == 'u')
		return (print_unsigned(va_arg(*args, unsigned int), flags));
	if (c == 'p')
		return (print_ptr(va_arg(*args, unsigned long), flags));
	if (c == 'x')
		return (print_hex(va_arg(*args, unsigned int), flags, 1));
	if (c == 'X')
		return (print_hex(va_arg(*args, unsigned int), flags, 0));
	return (-1);
}
