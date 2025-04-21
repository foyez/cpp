/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:38:27 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 20:32:44 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates the first occurrence of c (converted to an unsigned char)
/// in string s.
/// @param str
/// @param c
/// @param n
/// @return a pointer to the byte located,
///	or NULL if no such byte exists within n bytes.
void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)str;

	while (n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
