/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:24:19 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/25 23:13:49 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	size = (max - min);
	range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	size;
// 	int	*arr;

// 	min = 1;
// 	max = 5;
// 	size = (max - min);
// 	arr = ft_range(min, max);
// 	if (!arr)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d\n", arr[i]);
// 	}
// 	free(arr);
// 	return (0);
// }
