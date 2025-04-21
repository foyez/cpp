/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:55:03 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:31:55 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends the string src to the end of dst, ensuring that the result
 *        is null-terminated and does not exceed the size specified by dstsize.
 *        The function will not write more than dstsize - 1 characters to dst.
 *
 * @param dst      Pointer to the destination buffer.
 * @param src      Pointer to the source string to be appended to dst.
 * @param dstsize  Size of the destination buffer, including the null-terminator.
 *
 * @return The total length of the string it tried to create (i.e., the initial
 *         length of dst + the length of src). If the return value is >= dstsize,
 *         truncation occurred. Otherwise, the entire src was appended to dst.
 *
 * @note If dstsize is smaller than the length of dst, no characters will be
 * appended. If dstsize is greater than or equal to the length of dst, the
 * entire src string will be appended, provided there is enough space.
 * The function does not overwrite the null-terminator of dst if dstsize
 * is greater than the length of dst, and it ensures that the result is
 * always null-terminated.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size == 0 || size <= d_len)
		return (s_len + size);
	i = 0;
	while (src[i] && i < size - d_len - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char dest[20] = "Hello, ";  // destination buffer
//     const char *src = "world!";  // source string

//     // size_t result = strlcat(dest, src, sizeof(dest));
// 	size_t result = ft_strlcat(dest, src, sizeof(dest));

// 	printf("Sizeof dst: %zu\n", sizeof(dest));
//     printf("Resulting string: %s\n", dest);  // Output: "Hello, world!"
//     printf("Total length tried to create: %zu\n", result);

// 	return (0);
// }
