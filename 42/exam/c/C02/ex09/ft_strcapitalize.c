/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:36:25 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/20 14:39:04 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize;

	capitalize = 1;
	ft_lowercase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (capitalize)
			{
				str[i] -= ('a' - 'A');
			}
			capitalize = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			capitalize = 0;
		else
			capitalize = 1;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "salut, comment ? 42mots quarante-deux; cinquante+et+un";

// 	printf("Before: %s\n", str);
// 	printf("After: %s\n", ft_strcapitalize(str));
// 	return (0);
// }
