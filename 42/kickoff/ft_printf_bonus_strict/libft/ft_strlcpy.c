/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:35:04 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 14:24:21 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to (dstsize - 1) characters from the string src to dst,
 *        ensuring the result is null-terminated.
 *
 * @param dst      Pointer to the destination buffer.
 * @param src      Pointer to the source string to be copied.
 * @param dstsize  Size of the destination buffer.
 *
 * @return The total length of src (not limited by dstsize), which means:
 *         - If return value is >= dstsize, truncation occurred.
 *         - If return value is < dstsize, the entire src was copied.
 *
 * @note Unlike strncpy, ft_strlcpy always null-terminates dst (if dstsize > 0).
 *       If dstsize is 0, the function still calculates the length of src but
 *       does not write anything to dst.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char source[] = "Hello, world!";
//     char dest[20];

// 	size_t result = ft_strlcpy(dest, source, sizeof(dest));

//     printf("Source: %s\n", source);
//     printf("Destination: %s\n", dest);
//     printf("Returned value: %zu\n", result);

//     return (0);
// }
