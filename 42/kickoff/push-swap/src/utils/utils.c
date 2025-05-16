/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:59:52 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/15 20:41:34 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

int	ft_max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
