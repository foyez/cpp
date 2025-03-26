/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:45:02 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/26 12:34:52 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else if (num > 9)
		ft_putchar_fd(num - 10 + 'a', 1);
	else
		ft_putchar_fd(num + '0', 1);
}

static int	ft_ptrlen(unsigned long long ptr)
{
	if (ptr == 0)
		return (3);
	return (2 + ft_hexlen(ptr));
}

static int	ft_putptr_content(unsigned long long ptr)
{
	int	len;

	len = ft_putstr("0x");
	if (len == -1)
		return (-1);
	if (ptr == 0)
		return (len + write(1, "0", 1));
	ft_putptr(ptr);
	return (len + ft_hexlen(ptr));
}

// Effect: -
// No effect: +, #, 0, . and space
int	ft_print_ptr(unsigned long long ptr, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	len = ft_ptrlen(ptr);
	if (flags.left_align)
		count += ft_putptr_content(ptr);
	count += ft_pad_width(flags.width, len, 0);
	if (!flags.left_align)
		count += ft_putptr_content(ptr);
	return (count);
}
