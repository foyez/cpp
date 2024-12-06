/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:04:03 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/22 22:54:43 by kaahmed          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	j = ft_strlen(dest);
	d_len = j;
	s_len = ft_strlen(src);
	if (size == 0 || size <= d_len)
	{
		return (s_len + size);
	}
	while (src[i] != '\0' && i < size - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dest[11] = "Hello ";
// 	char	src[] = "World!";

// 	// printf("%lu\n", strlcat(dest, src, sizeof(dest)));
// 	printf("%u\n", ft_strlcat(dest, src, sizeof(dest)));
// 	printf("%s\n", dest);
// }
