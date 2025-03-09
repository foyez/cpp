/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:59:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/08 11:56:30 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

// int is_longer_than_3(char *str)
// {
// 	int len = 0;
// 	while (str[len])
// 		len++;
// 	return (len > 3);
// }

// #include <stdio.h>
// int main()
// {
// 	char *arr[] = {"apple", "banana", "mango", "cat", NULL};
// 	int res = ft_count_if(arr, is_longer_than_3);
// 	printf("Number of strings with length > 3: %d\n", res);

// 	return (0);
// }
