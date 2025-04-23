/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:53 by kaahmed           #+#    #+#             */
/*   Updated: 2025/04/23 02:20:33 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			format = parse_flags(format, &flags);
			ret = handle_format(*format, &args, flags);
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
