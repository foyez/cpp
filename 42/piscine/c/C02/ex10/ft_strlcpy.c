/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:03 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/20 14:45:08 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*s2 = "Hello";
// 	size_t		result;
// 	char		s1[10];

// 	result = strlcpy(s1, s2, sizeof(s1));
// 	printf("Copied string: %s\n", s1);
// 	printf("Return value: %zu\n", strlcpy(s1, s2, sizeof(s1)));
// 	return (0);
// }
