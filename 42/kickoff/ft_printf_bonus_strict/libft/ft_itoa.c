/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:58:01 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/21 16:12:58 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

/// @brief Allocates memory (using malloc(3)) and returns
/// a string representing the integer received as an
/// argument. Negative numbers must be handled.
/// @param n
/// @return The string representing the integer.
/// NULL if the allocation fails.
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_nbrlen(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		return (str[0] = '0', str);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
