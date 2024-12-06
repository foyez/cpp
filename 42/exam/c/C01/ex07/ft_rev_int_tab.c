/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:27:11 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/17 01:09:40 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	arr[] = {1, 2, 3};

// 	ft_rev_int_tab(arr, 3);
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%d", arr[i]);
// 	}
// }
