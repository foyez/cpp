/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabic <zbabic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:50:03 by zbabic            #+#    #+#             */
/*   Updated: 2025/03/21 16:16:59 by zbabic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_put_pointer_recursive_fd(unsigned long long addr,
	unsigned int counter, int fd)
{
	unsigned char	hex_digit;
	unsigned int	hex_digit_int;
	int				temp_counter;

	hex_digit_int = addr % 16;
	if (hex_digit_int >= 10)
		hex_digit = 'a' + (hex_digit_int - 10);
	else
		hex_digit = '0' + hex_digit_int;
	if (addr < 16)
	{
		if (ft_putchar_fd(hex_digit, 1) == -1)
			return (-1);
		return (counter + 1);
	}
	else
	{
		temp_counter = ft_put_pointer_recursive_fd(addr / 16, counter + 1, fd);
		if (temp_counter == -1 || ft_putchar_fd(hex_digit, 1) == -1)
			return (-1);
		return (temp_counter);
	}
}

int	ft_put_pointer_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					ret_value;

	addr = (unsigned long long)ptr;
	if (write(fd, "0x", 2) == -1)
		return (-1);
	ret_value = ft_put_pointer_recursive_fd(addr, 0, 1);
	if (ret_value == -1)
		return (ret_value);
	else
		return (ret_value + 2);
}

int	handle_p(va_list args, size_t *num_char)
{
	int	ret_value;

	ret_value = ft_put_pointer_fd(va_arg(args, void *), 1);
	if (ret_value == -1)
		return (-1);
	else
	{
		*num_char += ret_value;
		return (0);
	}
}
