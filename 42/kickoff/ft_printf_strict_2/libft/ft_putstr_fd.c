/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabic <zbabic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:13:42 by zbabic            #+#    #+#             */
/*   Updated: 2025/03/21 15:58:54 by zbabic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		if (ft_putchar_fd(s[counter], fd) == -1)
			return (-1);
		++counter;
	}
	return (0);
}
