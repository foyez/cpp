/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:54:46 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/08 12:54:28 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;
	int	i;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	fact = 1;
	while (i <= nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d", ft_iterative_factorial(12));
// 	return (0);
// }
