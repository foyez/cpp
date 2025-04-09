/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabic <zbabic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:38:00 by zbabic            #+#    #+#             */
/*   Updated: 2025/03/21 15:33:28 by zbabic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	f_putnbr_fd_recursive(long num, int fd)
{
	char	char_digit;
	int		digit;

	if (num < 10)
	{
		char_digit = '0' + num;
		if (ft_putchar_fd(char_digit, 1) == -1)
			return (-1);
		return (0);
	}
	else
	{
		digit = num % 10;
		char_digit = '0' + digit;
		if (f_putnbr_fd_recursive(num / 10, fd) == -1)
			return (-1);
		return (ft_putchar_fd(char_digit, 1));
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
		num = -num;
	}
	return (f_putnbr_fd_recursive(num, fd));
}
