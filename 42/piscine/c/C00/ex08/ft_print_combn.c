/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:30:53 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/16 22:57:58 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int n)
{
	ft_putchar('0' + n);
}

void	ft_print_number(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnum(arr[i]);
		i++;
	}
	if (arr[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_generate_comb(int *arr, int n, int start, int index)
{
	int	num;

	if (index == n)
	{
		ft_print_number(arr, n);
		return ;
	}
	num = start;
	while (num < 10)
	{
		arr[index] = num;
		ft_generate_comb(arr, n, num + 1, index + 1);
		num++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n >= 10 || n <= 0)
	{
		return ;
	}
	ft_generate_comb(arr, n, 0, 0);
}
