/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:20:48 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/04 04:36:22 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*strs;

	strs = (t_stock_str *)malloc(sizeof(*strs) * (ac + 1));
	if (!strs || ac < 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		if (!strs[i].copy)
		{
			while (i > 0)
				free(strs[--i].copy);
			free(strs);
			return (NULL);
		}
		i++;
	}
	strs[i].str = 0;
	return (strs);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stock_str	*strs;
// 	int			i;

// 	strs = ft_strs_to_tab(argc, argv);
// 	i = 0;
// 	while (strs[i].str)
// 	{
// 		printf("%s %p\n", strs[i].str, strs[i].str);
// 		printf("%s %p\n", strs[i].copy, strs[i].copy);
// 		printf("%d\n", strs[i].size);
// 		i++;
// 	}
// 	while (i > 0)
// 		free(strs[--i].copy);
// 	free(strs);
// 	return (0);
// }
