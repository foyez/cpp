/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:27 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 15:48:17 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates memory (using malloc(3)) and returns a
/// substring from the string ’str’.
/// The substring starts at index ’start’ and has a
/// maximum length of ’len’.
/// @param str
/// @param start
/// @param len
/// @return The substring.
/// NULL if the allocation fails.
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	strlen;
	size_t	sublen;

	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	if (start >= strlen || len == 0)
		return (ft_strdup(""));
	sublen = strlen - start;
	if (sublen < len)
		len = sublen;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, str + start, len + 1);
	return (sub);
}
