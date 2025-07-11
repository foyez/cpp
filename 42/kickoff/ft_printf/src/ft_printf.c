/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:53 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/27 20:09:46 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_error(va_list args)
{
	va_end(args);
	return (-1);
}

// A va_list is not just a simple pointer —
// it contains internal state (like current argument position)
// If we pass it by value or use it twice without copying,
// it can behave incorrectly on many systems.
int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int		count;
	int		ret;
	t_flags	flags;
	va_list	args_copy;

	va_copy(args_copy, args);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			format = parse_flags(format, &flags);
			ret = handle_format(fd, *format, args_copy, flags);
		}
		else
			ret = ft_putchar(fd, *format);
		if (ret == -1)
			return (ft_error(args));
		count += ret;
		format++;
	}
	va_end(args_copy);
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vdprintf(fd, format, args);
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vdprintf(1, format, args);
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
