/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:40:39 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/25 12:37:13 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list *args, t_flags flags)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int), flags));
	if (c == '%')
		return (ft_print_char('%', flags));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *), flags));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int), flags));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int), flags));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, unsigned long long), flags));
	if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), flags, 1));
	if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), flags, 0));
	return (0);
}
