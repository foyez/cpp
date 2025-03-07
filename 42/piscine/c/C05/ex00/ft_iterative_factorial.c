/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:33:05 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/21 21:42:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;
	int	i;

	if (nb < 0)
	{
		return (0);
	}
	fact = 1;
	i = 1;
	while (i <= nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_factorial(5));
// 	return (0);
// }
