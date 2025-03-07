/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:37:52 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/21 00:43:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

int	is_printable_char(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable_char(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_putnbr_hex((unsigned char)str[i]);
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("This\tis\ta\ttest.\nIt includes tabs.");
// }
