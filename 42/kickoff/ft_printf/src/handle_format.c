/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:39:36 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/16 16:17:41 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(int fd, char c, va_list args, t_flags flags)
{
	if (c == 'c')
		return (print_char(fd, va_arg(args, int), flags));
	if (c == '%')
		return (print_char(fd, '%', flags));
	if (c == 's')
		return (print_str(fd, va_arg(args, char *), flags));
	if (c == 'd' || c == 'i')
		return (print_nbr(fd, va_arg(args, int), flags));
	if (c == 'u')
		return (print_unsigned(fd, va_arg(args, unsigned int), flags));
	if (c == 'p')
		return (print_ptr(fd, va_arg(args, unsigned long), flags));
	if (c == 'x')
		return (print_hex(fd, va_arg(args, unsigned int), flags, 1));
	if (c == 'X')
		return (print_hex(fd, va_arg(args, unsigned int), flags, 0));
	return (-1);
}
