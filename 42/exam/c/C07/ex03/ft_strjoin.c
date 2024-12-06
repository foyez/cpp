/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:24:56 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/03 20:13:15 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_totallen(char **strs, int size, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*cur;
	int		len;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	len = ft_str_totallen(strs, size, sep);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	cur = res;
	i = 0;
	while (i < size)
	{
		ft_strcpy(cur, strs[i]);
		cur += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(cur, sep);
			cur += ft_strlen(sep);
		}
		i++;
	}
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs[] = {"Hi", "nice", "world bye!"};

// 	printf("%s\n", ft_strjoin(3, strs, ", "));
// }
