/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:21:25 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 13:39:30 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief  It writes n zeroed bytes to the string s.
/// If n is zero, bzero() does nothing.
/// @param str
/// @param size
void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n--)
		*ptr++ = '\0';
}

// #include <string.h>
// #include <stdio.h>

// int main() {
//     char str[50] = "Hello, World!";

//     printf("Before bzero: %s\n", str);

//     // Zero out the string using bzero
//     // bzero(str, sizeof(str));
// 	ft_bzero(str, sizeof(str));

//     printf("After bzero: %s\n", str);  // This will print an empty string

//     return (0);
// }
