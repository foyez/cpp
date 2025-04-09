/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabic <zbabic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:28:03 by zbabic            #+#    #+#             */
/*   Updated: 2025/03/24 01:02:06 by zbabic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifiers(const char *format, va_list args, size_t *cnt,
		size_t *num_char)
{
	int	ret_value;

	if (format[*cnt] && format[*cnt] == 'c')
		ret_value = handle_c(args, num_char);
	else if (format[*cnt] && format[*cnt] == 's')
		ret_value = handle_s(args, num_char);
	else if (format[*cnt] && (format[*cnt] == 'd' || format[*cnt] == 'i'))
		ret_value = handle_di(args, num_char);
	else if (format[*cnt] && format[*cnt] == 'x')
		ret_value = handle_hex(args, num_char, 0);
	else if (format[*cnt] && format[*cnt] == 'X')
		ret_value = handle_hex(args, num_char, 1);
	else if (format[*cnt] && format[*cnt] == 'p')
		ret_value = handle_p(args, num_char);
	else if (format[*cnt] && format[*cnt] == 'u')
		ret_value = handle_u(args, num_char);
	else if (format[*cnt] && format[*cnt] == '%')
	{
		*num_char += 1;
		ret_value = ft_putchar_fd('%', 1);
	}
	else
		return (-1);
	*cnt += 1;
	return (ret_value);
}

static int	handle_normal_character(const char *format, size_t *cnt,
		size_t *num_char)
{
	int	ret_value;

	ret_value = ft_putchar_fd(format[*cnt], 1);
	*num_char += 1;
	*cnt += 1;
	return (ret_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	cnt;
	size_t	num_char;

	num_char = 0;
	cnt = 0;
	va_start(args, format);
	while (1)
	{
		if (!format[cnt])
			break ;
		else if (format[cnt] == '%')
		{
			++cnt;
			if (handle_specifiers(format, args, &cnt, &num_char) == -1)
				return (va_end(args), -1);
		}
		else
		{
			if (handle_normal_character(format, &cnt, &num_char) == -1)
				return (va_end(args), -1);
		}
	}
	va_end(args);
	return (num_char);
}
// #include <stdio.h>
// int main()
// {
// 	// int mama = 5;
// 	// printf("asdhaksdjalsd");
// 	// printf("\n------------\n");
// 	// printf("OVOLIKOOO:%d",
// 			ft_printf("a%usdhjkasdasdasdha%cjskdhasja\nsd%sbabi%ia%dsd%x%%%p",
// 				-1, 'k', "ja se zovem zarko", 48, 44, 10, &mama));
// // 	// printf("\n------------\n");
// // 	// printf("OVOLIKOOO:%d",
// 			printf("a%usdhjkasdasdasdha%cjskdhasja\nsd%sbabi%ia%dsd%x%%%p", -1,
// 				'k', "ja se zovem zarko", 48, 44, 10, &mama));

// 	printf("%d", printf("%%"));
// 	printf("\n");
// // 	ft_printf("%s", "some string with %s hehe");
// // 	printf("\n");
// // 	printf("%s", "some string with %s hehe");

// 	// printf("OVOLIKO: %d", ft_printf("%%"));
// 	// printf("\n");
// 	// printf("OVOLIKO: %d", printf("%%"));
// 	// printf("\001\002\007\v\010\f\r\n", NULL);
// 	return (0);
// }