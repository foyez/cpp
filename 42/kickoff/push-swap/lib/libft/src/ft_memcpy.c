/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:34:15 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 13:57:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief It copies n bytes from memory area src to memory area dst.
/// If dst and src overlap, behavior is undefined.  Applications in which dst
/// and src might overlap should use memmove(3) instead.
/// @param dst
/// @param src
/// @param n
/// @return the original value of dst.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[] = "Hello, World!";
//     printf("Before memcpy: %s\n", str);
//     memcpy(str + 1, str, 5);
//     printf("After memcpy:  %s\n", str);

// 	char str2[] = "Hello, World!";
// 	printf("\nBefore memmove: %s\n", str2);
// 	// Move "World!" to the beginning of the string
// 	ft_memmove(str2 + 1, str2, 5);  // Overlapping region: shifting right
//     printf("After memmove:  %s\n", str2);

//     return (0);
// }
