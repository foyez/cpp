/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:52:17 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/05 00:18:29 by kaahmed          ###   ########.fr       */
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

	// if (nb <= 1)
	// 	return (0);
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

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_is_prime(7));
// 	printf("%d\n", ft_is_prime(2147483647));
// }
