/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:54:46 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:02:42 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_flags flags)
{
	int	count;
	int	ret;

	count = 0;
	if (flags.left_align)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		count++;
	}
	ret = ft_putpad(flags.width, 1, flags.zero_pad);
	if (ret == -1)
		return (-1);
	count += ret;
	if (!flags.left_align)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		count++;
	}
	return (count);
}
