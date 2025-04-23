/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:10:06 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:10:17 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str, t_flags flags)
{
	int	count;
	int	ret;
	int	strlen;
	int	printlen;

	count = 0;
	ret = 0;
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	printlen = strlen;
	if (flags.precision_set && flags.precision < printlen)
		printlen = flags.precision;
	if (flags.left_align)
	{
		ret = ft_putnstr(str, printlen);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putpad(flags.width, printlen, 0);
	if (ret == -1)
		return (-1);
	count += ret;
	if (!flags.left_align)
	{
		ret = ft_putnstr(str, printlen);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}
