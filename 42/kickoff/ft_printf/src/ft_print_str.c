/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:41:55 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/24 22:46:50 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Effect: - and .
// No effect: 0, #, + and space
int	ft_print_str(const char *str, t_flags flags)
{
	int	len;
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;
	if (flags.left_align)
		count += write(1, str, len);
	count += ft_pad_width(flags.width, len, 0);
	if (!flags.left_align)
		count += write(1, str, len);
	return (count);
}
