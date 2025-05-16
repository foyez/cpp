/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:20:09 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/14 16:27:01 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	return ((char *)ft_memcpy(dst, src, len + 1));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	printf("%s\n", strdup(NULL));
// 	return (0);
// }
