/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:53 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/21 18:41:11 by kaahmed          ###   ########.fr       */
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

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h> // for NULL

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putnchar(char c, int n)
{
	int i = 0;
	while (i < n)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		i++;
	}
	return n;
}

int ft_putstrn(const char *s, int n)
{
	int i = 0;
	if (!s)
		s = "(null)";
	while (s[i] && i < n)
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return i;
}

int ft_print_char(char c, int width, int left_align, int zero_pad)
{
	int count = 0;
	int pad_len = width > 1 ? width - 1 : 0;

	if (!left_align)
	{
		int ret = ft_putnchar(zero_pad ? '0' : ' ', pad_len);
		if (ret == -1)
			return (-1);
		count += ret;
	}

	if (ft_putchar(c) == -1)
		return (-1);
	count++;

	if (left_align)
	{
		int ret = ft_putnchar(' ', pad_len);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return count;
}

int ft_strlen(const char *s)
{
	int len = 0;
	while (s && s[len])
		len++;
	return len;
}

int ft_print_string(const char *s, int width, int precision, int precision_set, int left_align)
{
	int count = 0;
	int str_len = s ? ft_strlen(s) : 6; // "(null)" is 6 chars
	int print_len = str_len;

	if (!s)
		s = "(null)";
	if (precision_set && precision < print_len)
		print_len = precision;

	int pad_len = width > print_len ? width - print_len : 0;

	if (!left_align)
	{
		int ret = ft_putnchar(' ', pad_len);
		if (ret == -1)
			return (-1);
		count += ret;
	}

	int ret = ft_putstrn(s, print_len);
	if (ret == -1)
		return (-1);
	count += ret;

	if (left_align)
	{
		ret = ft_putnchar(' ', pad_len);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return count;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int total = 0;
	int i = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			int left_align = 0;
			int zero_pad = 0;
			int width = 0;
			int precision = 0;
			int precision_set = 0;

			// flags
			while (format[i] == '-' || format[i] == '0' || format[i] == '#' ||
				   format[i] == '+' || format[i] == ' ' || format[i] == '.')
			{
				if (format[i] == '-')
					left_align = 1;
				else if (format[i] == '0')
					zero_pad = 1;
				else if (format[i] == '.')
				{
					precision_set = 1;
					precision = 0;
					i++;
					while (format[i] >= '0' && format[i] <= '9')
					{
						precision = precision * 10 + (format[i] - '0');
						i++;
					}
					continue;
				}
				i++;
			}

			// width
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - '0');
				i++;
			}

			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				int ret = ft_print_char(c, width, left_align, zero_pad);
				if (ret == -1)
					return (-1);
				total += ret;
				i++;
			}
			else if (format[i] == 's')
			{
				const char *s = va_arg(args, const char *);
				int ret = ft_print_string(s, width, precision, precision_set, left_align);
				if (ret == -1)
					return (-1);
				total += ret;
				i++;
			}
			else
			{
				// unrecognized specifier
				if (ft_putchar('%') == -1 || ft_putchar(format[i]) == -1)
					return (-1);
				total += 2;
				i++;
			}
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			total++;
			i++;
		}
	}
	va_end(args);
	return total;
}