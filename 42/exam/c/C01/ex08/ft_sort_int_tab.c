/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foyez <foyez@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:27:32 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/06 08:14:28 by foyez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[min_index] > tab[j])
			{
				min_index = j;
			}
			j++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[i];
		tab[i] = temp;
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	arr[5] = {3, 4, 2, 7, 1};

	ft_sort_int_tab(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return (0);
}
