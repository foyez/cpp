/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:00:49 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:44:17 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies 'len' bytes from 'src' to 'dst',
///	handling memory overlap safely.
/// Unlike memcpy(), memmove() ensures that overlapping memory regions
/// are copied correctly by adjusting the copy direction if needed.
/// If 'dst' is before 'src', copying proceeds forward; otherwise,
///	copying is done in reverse to prevent data corruption.
/// @param dst Pointer to the destination buffer.
/// @param src Pointer to the source buffer.
/// @param len Number of bytes to copy.
/// @return the original value of dst.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!src && !dst)
		return (NULL);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		*((char *)dst + len) = *((char *)src + len);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str1[] = "HelloWorld"; // Original string
// 	// Overlapping copy: Move "World" (index 5) to start (index 0)
// 	printf("Before memmove: %s\n", str1);
// 	// ft_memmove(str1, str1 + 5, 5);
// 	printf("After memmove (forward move): %s\n", ft_memmove(str1, str1 + 5, 5));
// 	char str2[] = "HelloWorld"; // Reset string
// 	// Overlapping copy: Move "Hello" (index 0) to index 5
// 	printf("\nBefore memmove: %s\n", str2);
// 	// ft_memmove(str2 + 5, str2, 5)
// 	printf("After memmove (backward move): %s\n", ft_memmove(str2 + 5, str2,
// 			5));
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[] = "Hello, World!";
//     printf("Before memcpy: %s\n", str);
//     ft_memcpy(str + 1, str, 5);
//     printf("After memcpy:  %s\n", str);

// 	char str2[] = "Hello, World!";
// 	printf("\nBefore memmove: %s\n", str2);
// 	// Move "World!" to the beginning of the string
// 	ft_memmove(str2 + 1, str2, 5);  // Overlapping region: shifting right
//     printf("After memmove:  %s\n", str2);

//     return 0;
// }
