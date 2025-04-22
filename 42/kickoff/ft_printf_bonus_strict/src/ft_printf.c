/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:53 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/22 20:36:26 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		count;
// 	t_flags	flags;
// 	int		ret;

// 	count = 0;
// 	va_start(args, format);
// 	while (*format)
// 	{
// 		if (*format == '%' && *(format + 1))
// 		{
// 			format++;
// 			format = ft_parse_flags(format, &flags);
// 			ret = ft_handle_format(*format, &args, flags);
// 		}
// 		else
// 			ret = ft_putchar(*format);
// 		if (ret == -1)
// 			return (ft_error(args));
// 		count += ret;
// 		format++;
// 	}
// 	va_end(args);
// 	return (count);
// }

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_flags
{
	int				left_align;
	int				width;
	int				precision;
	int				precision_set;
	int				zero_pad;
	int				plus_sign;
	int				space;
	int				alt_form;
}					t_flags;

static t_flags	*ft_init_flags(t_flags *flags)
{
	flags->left_align = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->precision_set = 0;
	flags->zero_pad = 0;
	flags->plus_sign = 0;
	flags->space = 0;
	flags->alt_form = 0;
	return (flags);
}

static const char	*ft_parse_num(const char *format, int *num)
{
	*num = 0;
	while (*format >= '0' && *format <= '9')
	{
		*num = *num * 10 + (*format - '0');
		format++;
	}
	return (format);
}

static t_flags	ft_left_align(t_flags flags)
{
	flags.left_align = 1;
	flags.zero_pad = 0;
	return (flags);
}

static t_flags	ft_plus_sign(t_flags flags)
{
	flags.plus_sign = 1;
	flags.space = 0;
	return (flags);
}

const char	*ft_parse_flags(const char *fmt, t_flags *flags)
{
	ft_init_flags(flags);
	while (*fmt == '-' || *fmt == '0' || *fmt == '+' || *fmt == ' '
		|| *fmt == '#')
	{
		if (*fmt == '-')
			*flags = ft_left_align(*flags);
		if (*fmt == '0' && !flags->left_align)
			flags->zero_pad = 1;
		if (*fmt == '+')
			*flags = ft_plus_sign(*flags);
		if (*fmt == ' ' && !flags->plus_sign)
			flags->space = 1;
		if (*fmt == '#')
			flags->alt_form = 1;
		fmt++;
	}
	fmt = ft_parse_num(fmt, &flags->width);
	if (*fmt == '.')
	{
		fmt++;
		flags->precision_set = 1;
		flags->precision = 0;
		flags->zero_pad = 0;
		fmt = ft_parse_num(fmt, &flags->precision);
	}
	return (fmt);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

// int	ft_putnchar(char c, int n)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	while (i < n)
// 	{
// 		ret = ft_putchar(c);
// 		if (ret == -1)
// 			return (-1);
// 		i++;
// 	}
// 	return (n);
// }

int	ft_putnchar(char c, int n)
{
	char	buf[1024];
	int		ret;
	int		written;
	int		i;
	int		chunk;

	written = 0;
	if (n <= 0)
		return (0);
	// Fill buffer manually
	i = 0;
	while (i < 1024)
		buf[i++] = c;
	// Write in chunks
	while (n > 0)
	{
		chunk = (n > 1024) ? 1024 : n;
		ret = write(1, buf, chunk);
		if (ret != chunk)
			return (-1);
		written += ret;
		n -= chunk;
	}
	return (written);
}

int	ft_putpad(int width, int len, int zero_pad)
{
	char	pad_ch;
	int		padlen;

	pad_ch = ' ';
	padlen = 0;
	if (width > len)
		padlen = width - len;
	if (zero_pad)
		pad_ch = '0';
	return (ft_putnchar(pad_ch, padlen));
}

int	ft_print_char(char c, t_flags flags)
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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	ft_putnstr(const char *s, int n)
{
	int	ret;

	// int i = 0;
	if (!s)
		s = "(null)";
	ret = write(1, s, n);
	if (ret != n)
		return (-1);
	return (ret);
	// while (s[i] && i < n)
	// {
	// 	if (ft_putchar(s[i]) == -1)
	// 		return (-1);
	// 	i++;
	// }
	// return (i);
}

int	ft_print_str(const char *str, t_flags flags)
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

static int	ft_utoa_ptr(unsigned long num, char *buf)
{
	const char	*hex = "0123456789abcdef";
	int			i;

	i = 0;
	if (num == 0)
	{
		buf[i++] = '0';
		return (i);
	}
	while (num)
	{
		buf[i++] = hex[num % 16];
		num /= 16;
	}
	return (i);
}

static int	ft_utoa_hex(unsigned int num, char *buf, int low)
{
	const char	*hex = "0123456789abcdef";
	int			i;
	int			rem;

	i = 0;
	if (num == 0)
	{
		buf[i++] = '0';
		return (i);
	}
	while (num)
	{
		rem = num % 16;
		if (rem > 9 && !low)
			buf[i++] = hex[rem] - 32;
		else
			buf[i++] = hex[rem];
		num /= 16;
	}
	return (i);
}

int	ft_itoa(int n, char *buf)
{
	unsigned int	num;
	int				i;

	i = 0;
	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)n;
	if (num == 0)
		buf[i++] = '0';
	while (num)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	return (i);
}

int	ft_utoa(unsigned int n, char *buf)
{
	int	i;

	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (i);
}

int	ft_putptr(char *buf, int len)
{
	int	count;
	int	ret;

	count = 0;
	ret = write(1, "0x", 2);
	if (ret != 2)
		return (-1);
	count += ret;
	// ret = write(1, buf, len);
	// if (ret == -1)
	// 	return (-1);
	// count += ret;
	while (--len >= 0)
	{
		if (ft_putchar(buf[len]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putprefix(int low)
{
	int	ret;

	ret = 0;
	if (low)
		ret = write(1, "0x", 2);
	else
		ret = write(1, "0X", 2);
	if (ret != 2)
		return (-1);
	return (2);
}

int	ft_print_hex(unsigned int num, t_flags flags, int low)
{
	int		count;
	int		ret;
	char	hex_buf[16];
	int		hexlen;
	int		prefixlen;
	int		zeros;
	int		i;

	count = 0;
	ret = 0;
	hexlen = ft_utoa_hex(num, hex_buf, low);
	prefixlen = 0;
	zeros = 0;
	if (flags.precision == 0 && num == 0)
		hexlen = 0;
	if (flags.alt_form && num != 0)
		prefixlen = 2;
	if (flags.precision_set && flags.precision > hexlen)
		zeros = flags.precision - hexlen;
	if (!flags.left_align)
	{
		ret = ft_putpad(flags.width, prefixlen + zeros + hexlen,
				flags.zero_pad);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (prefixlen > 0)
	{
		ret = ft_putprefix(low);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (zeros > 0)
	{
		ret = ft_putnchar('0', zeros);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	i = hexlen;
	while (--i >= 0)
	{
		if (ft_putchar(hex_buf[i]) == -1)
			return (-1);
		count++;
	}
	if (flags.left_align)
	{
		ret = ft_putpad(flags.width, prefixlen + zeros + hexlen, 0);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

static int	ft_put_sign(int is_negative, t_flags flags)
{
	if (is_negative)
		return (ft_putchar('-'));
	if (flags.plus_sign)
		return (ft_putchar('+'));
	else if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

int	ft_print_unsigned(unsigned int n, t_flags flags)
{
	int		count;
	char	buf[16];
	int		len;
	int		ret;
	int		zeros;
	int		i;

	count = 0;
	len = ft_utoa(n, buf);
	ret = 0;
	zeros = 0;
	if (flags.precision == 0 && n == 0)
		len = 0;
	if (flags.precision_set && flags.precision > len)
		zeros = flags.precision - len;
	if (!flags.left_align)
	{
		ret = ft_putpad(flags.width, len + zeros, flags.zero_pad);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (zeros > 0)
	{
		ret = ft_putnchar('0', zeros);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	i = len;
	while (--i >= 0)
	{
		if (ft_putchar(buf[i]) == -1)
			return (-1);
		count++;
	}
	if (flags.left_align)
	{
		ret = ft_putpad(flags.width, len + zeros, 0);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_print_nbr(int n, t_flags flags)
{
	int		count;
	char	buf[16];
	int		is_negative;
	int		len;
	int		zeros;
	int		ret;
	int		extra_char;
	int		i;

	count = 0;
	is_negative = n < 0;
	len = ft_itoa(n, buf);
	zeros = 0;
	ret = 0;
	if (flags.precision == 0 && n == 0)
		len = 0;
	extra_char = 0;
	if (is_negative || flags.plus_sign || flags.space)
		extra_char = 1;
	if (flags.precision_set && flags.precision > len)
		zeros = flags.precision - len;
	// if (!flags.left_align)
	// {
	// 	ret = ft_putpad(flags.width, len + zeros + extra_char, flags.zero_pad);
	// 	if (ret == -1)
	// 		return (-1);
	// 	count += ret;
	// }
	// ret = ft_put_sign(is_negative, flags);
	// if (ret == -1)
	// 	return (-1);
	// count += ret;
	// if (zeros > 0)
	// {
	// 	ret = ft_putnchar('0', zeros);
	// 	if (ret == -1)
	// 		return (-1);
	// 	count += ret;
	// }
	// while (--len >= 0)
	// {
	// 	if (ft_putchar(buf[len]) == -1)
	// 		return (-1);
	// 	count++;
	// }
	// if (flags.left_align)
	// {
	// 	ret = ft_putpad(flags.width, len + zeros + extra_char, 0);
	// 	if (ret == -1)
	// 		return (-1);
	// 	count += ret;
	// }
	if (!flags.left_align && flags.zero_pad && !flags.precision_set)
	{
		ret = ft_put_sign(is_negative, flags);
		if (ret == -1)
			return (-1);
		count += ret;
		ret = ft_putpad(flags.width, len + zeros + extra_char, 1);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	else
	{
		if (!flags.left_align)
		{
			ret = ft_putpad(flags.width, len + zeros + extra_char, 0);
			if (ret == -1)
				return (-1);
			count += ret;
		}
		ret = ft_put_sign(is_negative, flags);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (zeros > 0)
	{
		ret = ft_putnchar('0', zeros);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	i = len;
	while (--i >= 0)
	{
		if (ft_putchar(buf[i]) == -1)
			return (-1);
		count++;
	}
	if (flags.left_align)
	{
		ret = ft_putpad(flags.width, len + zeros + extra_char, 0);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_print_ptr(unsigned long ptr, t_flags flags)
{
	int		count;
	int		ret;
	char	hex_buf[32];
	int		hexlen;
	int		printlen;

	count = 0;
	ret = 0;
	hexlen = ft_utoa_ptr(ptr, hex_buf);
	printlen = 2 + hexlen;
	if (flags.left_align)
	{
		ret = ft_putptr(hex_buf, hexlen);
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
		ret = ft_putptr(hex_buf, hexlen);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_handle_format(char c, va_list *args, t_flags flags)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int), flags));
	if (c == '%')
		return (ft_print_char('%', flags));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *), flags));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int), flags));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int), flags));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, unsigned long), flags));
	if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), flags, 1));
	if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), flags, 0));
	return (-1);
}

int	ft_error(va_list args)
{
	va_end(args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;
	int		ret;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			format = ft_parse_flags(format, &flags);
			ret = ft_handle_format(*format, &args, flags);
		}
		else
			ret = ft_putchar(*format);
		if (ret == -1)
			return (ft_error(args));
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}

// #include <limits.h>
// #include <unistd.h>

// // "%-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d", 0, 5, -1, -10, 100,
// // -1862, INT_MIN, INT_MAX
// int	main(void)
// {
// 	int	x;
// 	int	ret;

// 	x = 42;
// 	// close(1); // Close STDOUT manually
// 	// ret = ft_printf("%u", 0);
// 	ret = ft_printf("%0#5x", 5);
// 	printf("\n%d\n", ret);
// 	// ret = printf("%-d, %-d, %-d, %-d, %-d, %-d, %-d, %-d", 0, 5, -1, -10,
// 	// 100,
// 	// 		-1862, INT_MIN, INT_MAX);
// 	ret = printf("%0#5x", 5);
// 	printf("\n%d\n", ret);
// 	if (ret == -1)
// 		write(2, "ft_printf failed!\n", 18); // fallback to stderr
// 	return (0);
// }
