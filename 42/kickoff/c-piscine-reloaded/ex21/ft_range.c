/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:22:44 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/07 16:43:07 by kaahmed          ###   ########.fr       */
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
	while (min < max)
		range[i++] = min++;
	return (range);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	int min = -4;
// 	int max = 4;
// 	int size = (max - min);
// 	int i = 0;
// 	int *range = ft_range(min, max);
// 	while (i < size)
// 		printf("%d ", range[i++]);
// 	free(range);
// 	return (0);
// }
