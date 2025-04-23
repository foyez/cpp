/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:54:46 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 20:21:10 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// No effect: 0, +, # and space
int	print_char(char c, t_flags flags)
{
	int	count;
	int	ret;

	count = 0;
	if (flags.left_align)
	{
		if (!safe_count(ft_putchar(c), &count))
			return (-1);
	}
	ret = ft_putpad(flags.width, 1, flags.zero_pad);
	if (!safe_count(ret, &count))
		return (-1);
	if (!flags.left_align)
	{
		if (!safe_count(ft_putchar(c), &count))
			return (-1);
	}
	return (count);
}
