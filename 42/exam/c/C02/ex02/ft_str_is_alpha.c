/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:06:44 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/20 23:48:02 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	bool	is_upper;
	bool	is_lower;

	i = 0;
	while (str[i] != '\0')
	{
		is_upper = (str[i] >= 'A' && str[i] <= 'Z');
		is_lower = (str[i] >= 'a' && str[i] <= 'z');
		if (!(is_upper || is_lower))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_alpha("hello"));
// 	printf("%d\n", ft_str_is_alpha(""));
// 	printf("%d\n", ft_str_is_alpha("hello5"));
// 	printf("%d\n", ft_str_is_alpha("ABcL"));
// 	return (0);
// }
