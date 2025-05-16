/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:57:54 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:33:38 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief It compares byte string s1 against byte string s2.
/// Both strings are assumed to be n bytes long.
/// @param s1
/// @param s2
/// @param n
/// @return The memcmp() function returns zero if the two strings are identical,
///	otherwise returns the difference between the first two differing bytes
/// (treated as unsigned char values, so that `\200' is greater than `\0',
///	for example).  Zero-length strings are always identical.  This behavior
/// is not required by C
/// and portable code should only depend on the sign of the returned value.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_ptr = (const unsigned char *)s1;
	const unsigned char	*s2_ptr = (const unsigned char *)s2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1_ptr[i] == s2_ptr[i])
		i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
