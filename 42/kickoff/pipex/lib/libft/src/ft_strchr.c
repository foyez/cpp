/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:22:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 14:45:06 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief It locates the first occurrence of c (converted to a char) in the
/// string pointed to by s.
/// The terminating null character is considered to be part of the string;
/// therefore if c is `\0', the functions locate the terminating `\0'.
/// @param s
/// @param c
/// @return a pointer to the located character,
///	or NULL if the character does not appear in the string.
/// @note The strrchr() function is identical to strchr(),
///	except it locates the last occurrence of c.
char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	ch;

	str = (char *)s;
	ch = (unsigned char)c;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (ch == '\0')
		return (str);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*str = "Hello, world!";
// 	char		ch;
// 	char		*result;

// 	ch = '\0';
// 	// Search for the character 'o' in the string
// 	// char *result = strchr(str, ch);
// 	result = ft_strchr(str, ch);
// 	if (result != NULL)
// 	{
// 		printf("Found character '%c' at '%s' at position: %ld\n", ch, result,
// 			result - str);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the string.\n", ch);
// 	}
// 	return (0);
// }
