/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:09:03 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/07 14:10:32 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arr[min_index], arr[j]) > 0)
				min_index = j;
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
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
