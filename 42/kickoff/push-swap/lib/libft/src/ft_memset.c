/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:17:20 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 13:37:15 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief It writes len bytes of value c (converted to an unsigned char)
/// to the string str.
/// @param str
/// @param c
/// @param len
/// @return its first argument.
void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[50] = "Hello, world!";

//     // Printing the original string
//     printf("Original string: %s\n", str);

//     // Use memset to set the first 5 characters of 'str' to 'X'
//     // memset(str, 'X', 5);
// 	ft_memset(str, 'X', 5);

//     // Printing the modified string
//     printf("Modified string: %s\n", str);

//     return (0);
// }
