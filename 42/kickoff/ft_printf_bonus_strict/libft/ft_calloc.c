/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:05:41 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/14 14:41:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (num_elements == 0 || size == 0)
		return (malloc(0));
	total_size = num_elements * size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

// void *ft_calloc(size_t count, size_t size)
// {
// 	size_t i;
// 	char *ptr;

// 	i = 0;
// 	ptr = (char *)malloc(sizeof(char) * (count * size));
// 	if (ptr == (void *)0)
// 		return (0);
// 	while (i)
// }
