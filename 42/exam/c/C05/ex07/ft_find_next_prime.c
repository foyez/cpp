/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:11:03 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/05 00:21:01 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_sqrt(int nb, int i)
{
	if (i * i > nb || i > 46340)
		return (i);
	if (i * i == nb)
		return (i);
	return (ft_recursive_sqrt(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_recursive_sqrt(nb, 0));
}

int	ft_is_prime(int nb)
{
	int	factor;
	int	nb_sqrt;

	if (nb <= 1)
		return (0);
	// if (nb <= 3)
	// 	return (1);
	// if (nb % 2 == 0 || nb % 3 == 0)
	// 	return (0);
	factor = 2;
	nb_sqrt = ft_sqrt(nb);
	while (factor <= nb_sqrt)
	{
		if (nb % factor == 0)
		{
			return (0);
		}
		factor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
	{
		return (2);
	}
	while (nb >= 2 && nb <= 2147483647)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_find_next_prime(4));
// 	printf("%d\n", ft_find_next_prime(7));
// 	printf("%d\n", ft_find_next_prime(2147483647));
// }
