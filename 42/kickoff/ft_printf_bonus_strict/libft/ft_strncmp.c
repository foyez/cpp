/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:21:28 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:43:49 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The strcmp() and strncmp() functions lexicographically compare
/// the null-terminated strings s1 and s2. The strncmp() function compares
/// not more than n characters.  Because strncmp() is designed for comparing
/// strings rather than binary data, characters that
/// appear after a `\0' character are not compared.
/// @param s1
/// @param s2
/// @param n
/// @return The strcmp() and strncmp() functions return an integer greater than,
///	equal to, or less than 0, according as the string s1 is greater than,
///	equal to, or less than the string s2.  The comparison is done using
/// unsigned characters, so that `\200' is greater than `\0'.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
