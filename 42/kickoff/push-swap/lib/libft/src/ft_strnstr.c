/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:16:51 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:42:30 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a substring in a string within
 * a specified length. This function searches for the first occurrence
 * of the null-terminated string `needle` within the string `haystack`,
 * but only up to `len` characters. The function stops searching
 * when it has searched `len` characters or when it finds the substring.
 *
 * @param haystack The string in which the search is performed.
 * @param needle The substring to search for within `haystack`.
 * @param len The maximum number of characters to search within `haystack`.
 *
 * @return If the `needle` is found within `haystack` (up to `len` characters),
 * a pointer to the beginning of the first occurrence of `needle` within
 * `haystack` is returned.
 * If `needle` is not found, or `len` is zero, `NULL` is returned.
 * If `needle` is an empty string, `haystack` is returned.
 *
 * @note The function does not require `needle` to be null-terminated as
 * long as `len` is properly set to avoid overflows.
 *
 * @example
 * char *haystack = "Hello, world!";
 * char *needle = "world";
 * char *result = ft_strnstr(haystack, needle, 10);
 * printf("Result: %s\n", result); // Output: "world!"
 */
char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*small)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && small[j] && big[i + j] == small[j] && (i
				+ j) < len)
			j++;
		if (!small[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
