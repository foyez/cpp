/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:20:31 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/20 23:16:37 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "hi";
// 	char	str2[] = "hello";

// 	printf("%s\n", ft_strncpy(str2, str1, 2));
// 	printf("%s\n", ft_strncpy(str2, str1, 4));
// 	// printf("%s\n", strncpy(str2, str1, 2));
// 	// printf("%s\n", strncpy(str2, str1, 4));
// 	return (0);
// }
