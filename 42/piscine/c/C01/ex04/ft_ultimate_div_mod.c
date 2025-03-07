/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:26:07 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/17 01:03:45 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_div;

	temp_div = *a / *b;
	*b = *a % *b;
	*a = temp_div;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 20;
// 	b = 2;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("%d, %d", a, b);
// }
