/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:58:40 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/28 14:57:11 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	i = 0;
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (size);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	*range;
// 	int	min;
// 	int	max;
// 	int	size;
// 	int	i;

// 	min = -5;
// 	max = 5;
// 	printf("%d\n", ft_ultimate_range(&range, min, max));
// 	size = max - min;
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", *(range++));
// 		i++;
// 	}
// }
