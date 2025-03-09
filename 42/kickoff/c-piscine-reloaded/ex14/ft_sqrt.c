/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:34:13 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/06 20:40:48 by kaahmed          ###   ########.fr       */
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
	{
		return (0);
	}
	return (ft_recursive_sqrt(nb, 0));
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_sqrt(64));
// 	printf("%d\n", ft_sqrt(65));
// 	return (0);
// }
