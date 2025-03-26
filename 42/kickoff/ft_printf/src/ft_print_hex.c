/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:14:04 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/25 16:49:21 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static int	ft_puthex(unsigned int num, char hex_char)
{
	if (num == 0)
		return (write(1, "0", 1));
	if (num >= 16)
	{
		ft_puthex(num / 16, hex_char);
		ft_puthex(num % 16, hex_char);
	}
	else if (num > 9)
		ft_putchar_fd(num - 10 + hex_char, 1);
	else
		ft_putchar_fd(num + '0', 1);
	return (ft_hexlen(num));
}

static int	ft_puthex_content(unsigned int num, t_flags flags, int low)
{
	char	hex_char;
	int		len;
	int		num_len;

	len = 0;
	if (num == 0 && flags.precision == 0)
		return (len);
	num_len = ft_hexlen(num);
	hex_char = 'a';
	if (!low)
		hex_char = 'A';
	while (num_len < flags.precision)
	{
		len += ft_putchar('0');
		flags.precision--;
	}
	return (len + ft_puthex(num, hex_char));
}

static int	ft_put_sign(unsigned int num, int alt_form, int low)
{
	int	len;

	len = 0;
	if (alt_form && num != 0)
	{
		len += ft_putchar('0');
		if (low)
			len += ft_putchar('x');
		else
			len += ft_putchar('X');
	}
	return (len);
}

// Effect: -, 0, ., and #
// No Effect: + and space
int	ft_print_hex(unsigned int num, t_flags flags, int low)
{
	int	count;
	int	content_len;

	count = 0;
	content_len = ft_hexlen(num);
	if (flags.precision > content_len)
		content_len = flags.precision;
	else if (num == 0 && flags.precision == 0)
		content_len = 0;
	if (flags.alt_form && num != 0)
		content_len += 2;
	if (flags.zero_pad || flags.left_align)
		count += ft_put_sign(num, flags.alt_form, low);
	if (flags.left_align)
		count += ft_puthex_content(num, flags, low);
	count += ft_pad_width(flags.width, content_len, flags.zero_pad);
	if (!flags.zero_pad && !flags.left_align)
		count += ft_put_sign(num, flags.alt_form, low);
	if (!flags.left_align)
		count += ft_puthex_content(num, flags, low);
	return (count);
}
