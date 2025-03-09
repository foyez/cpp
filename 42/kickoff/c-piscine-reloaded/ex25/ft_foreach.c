/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:50:27 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/07 16:56:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

// #include <stdio.h>
// void	ft_putnbr(int nbr)
// {
// 	printf("%d ", nbr);
// }

// #include <stdio.h>
// int main(void)
// {
// 	int tab[] = {1, 2, 3};
// 	ft_foreach(tab, 3, &ft_putnbr);
// 	return (0);
// }
