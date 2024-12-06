/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:48 by kaahmed           #+#    #+#             */
/*   Updated: 2024/12/03 21:24:52 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_sqrt(int nb, int i)
{
	if (i * i > nb || i > 46340)
		return (0);
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

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_sqrt(5));
// 	printf("%d\n", ft_sqrt(-5));
// 	printf("%d\n", ft_sqrt(2147395600));
// }
