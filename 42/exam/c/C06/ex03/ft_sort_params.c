/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:07:18 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/28 14:59:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort(char **arr, int size)
{
	int		i;
	int		j;
	int		min_index;
	char	*temp;

	i = 1;
	while (i < size - 1)
	{
		min_index = i;
		j = i;
		while (j < size)
		{
			if (ft_strcmp(arr[min_index], arr[j]) > 0)
			{
				min_index = j;
			}
			j++;
		}
		temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
