/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:02:14 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/26 12:33:25 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// No effect: 0, +, # and space
int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left_align)
		count += ft_putchar(c);
	count += ft_pad_width(flags.width, 1, flags.zero_pad);
	if (!flags.left_align)
		count += ft_putchar(c);
	return (count);
}
