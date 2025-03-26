/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:46:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/25 18:13:11 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

static int	ft_put_nbr_content(long n, t_flags flags)
{
	int	num_len;
	int	len;

	len = 0;
	if (n == 0 && flags.precision == 0)
		return (len);
	num_len = ft_longlen(n);
	while (num_len < flags.precision)
	{
		len += ft_putchar('0');
		flags.precision--;
	}
	ft_putnbr(n);
	len += num_len;
	return (len);
}

static int	ft_put_sign(int is_negative, t_flags flags)
{
	int	len;

	len = 0;
	if (is_negative)
		len += ft_putchar('-');
	else if (flags.plus_sign)
		len += ft_putchar('+');
	else if (flags.space)
		len += ft_putchar(' ');
	return (len);
}

static int	ft_print_content(t_flags flags, int is_negative, long nb,
		int content_len)
{
	int	len;

	len = 0;
	if (flags.zero_pad || flags.left_align)
		len += ft_put_sign(is_negative, flags);
	if (flags.left_align)
		len += ft_put_nbr_content(nb, flags);
	len += ft_pad_width(flags.width, content_len, flags.zero_pad);
	if (!flags.zero_pad && !flags.left_align)
		len += ft_put_sign(is_negative, flags);
	if (!flags.left_align)
		len += ft_put_nbr_content(nb, flags);
	return (len);
}

// Effect: -, 0, ., +, and space
// No effect: #
int	ft_print_nbr(int n, t_flags flags)
{
	int		len;
	int		is_negative;
	int		content_len;
	long	nb;

	len = 0;
	nb = n;
	is_negative = nb < 0;
	if (is_negative)
		nb = -nb;
	content_len = ft_longlen(nb);
	if (flags.precision > content_len)
		content_len = flags.precision;
	else if (n == 0 && flags.precision == 0)
		content_len = 0;
	if (is_negative || flags.plus_sign || flags.space)
		content_len++;
	len += ft_print_content(flags, is_negative, nb, content_len);
	return (len);
}
