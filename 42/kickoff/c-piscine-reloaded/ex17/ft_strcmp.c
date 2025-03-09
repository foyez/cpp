/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:55:55 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/06 21:08:41 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	// printf("%d\n", ft_strcmp("hi", "hi"));
// 	// printf("%d\n", ft_strcmp("hi", "hil"));
// 	printf("%d\n", strcmp("hif", "hib"));
// 	return (0);
// }
