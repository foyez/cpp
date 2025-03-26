/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:47:39 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/26 12:30:16 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if ((write(1, &c, 1)) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;
	int	ret;

	len = 0;
	while (*str)
	{
		ret = ft_putchar(*str++);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	return (len);
}

int	ft_pad_width(int width, int size, int zero)
{
	int	count;
	int	ret;

	count = 0;
	while (width - size > 0)
	{
		if (zero)
			ret = ft_putchar('0');
		else
			ret = ft_putchar(' ');
		if (ret == -1)
			return (-1);
		count += ret;
		size++;
	}
	return (count);
}

int	ft_longlen(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_error(va_list args)
{
	va_end(args);
	return (-1);
}
