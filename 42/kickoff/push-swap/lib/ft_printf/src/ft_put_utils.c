/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:50:49 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/27 10:15:14 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnchar(char c, int n)
{
	char	buf[1024];
	int		ret;
	int		count;
	int		i;
	int		chunk;

	count = 0;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < 1024 && i < n)
		buf[i++] = c;
	chunk = 1024;
	while (n > 0)
	{
		if (n < 1024)
			chunk = n;
		ret = write(1, buf, chunk);
		if (ret != chunk)
			return (-1);
		count += ret;
		n -= chunk;
	}
	return (count);
}

int	ft_putnstr(const char *s, int n)
{
	int	ret;

	ret = write(1, s, n);
	if (ret != n)
		return (-1);
	return (ret);
}

int	ft_putpad(int width, int contentlen, int zero_pad)
{
	char	pad_ch;
	int		padlen;

	pad_ch = ' ';
	padlen = 0;
	if (width > contentlen)
		padlen = width - contentlen;
	if (zero_pad)
		pad_ch = '0';
	return (ft_putnchar(pad_ch, padlen));
}

int	ft_putbuf(char *buf, int len, int zeros)
{
	int	ret;
	int	count;

	count = 0;
	if (zeros > 0)
	{
		ret = ft_putnchar('0', zeros);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	while (--len >= 0)
	{
		if (ft_putchar(buf[len]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
