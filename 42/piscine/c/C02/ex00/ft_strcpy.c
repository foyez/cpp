/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:52:00 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/17 21:36:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "hi";
// 	char	str2[] = "hello";

// 	printf("%s", ft_strcpy(str2, str1));
// 	printf("\n");
// 	printf("%s", str2);
// 	return (0);
// }
