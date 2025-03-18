/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:44:44 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 16:40:39 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates memory (using malloc(3)) and returns a
/// copy of ’s1’ with characters from ’set’ removed
/// from the beginning and the end.
/// @param s1
/// @param set
/// @return The trimmed string.
/// NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	trimmed_len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_len = end - start + 1;
	trimmed = (char *)malloc(sizeof(char) * trimmed_len);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], trimmed_len);
	return (trimmed);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strtrim("hello", "hel"));
// 	return (0);
// }
