/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:26:33 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/18 16:46:10 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Applies the function ’f’ to each character of the
// string passed as argument, passing its index as
// the first argument. Each character is passed by
// address to ’f’ so it can be modified if necessary.
/// @param s
/// @param f
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// #include <ctype.h>
// void to_upper_if_even(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 		*c = toupper(*c);
// }
// int main(void)
// {
// 	char str[] = "hello world";

// 	printf("Before %s\n", str);
// 	ft_striteri(str, to_upper_if_even);
// 	printf("After %s\n", str);

// 	return (0);
// }
