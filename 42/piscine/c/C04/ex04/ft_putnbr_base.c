/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:14:00 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/25 20:57:29 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkerror(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (len <= 1)
		return (1);
	while (i < len)
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '+' || str[i] == '-')
			return (1);
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;

	if (checkerror(base))
		return ;
	base_len = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < base_len)
		ft_putchar(base[nb]);
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base);
		ft_putnbr_base(nb % base_len, base);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_putnbr_base(-1100, "01");
// 	printf("\n");
// 	ft_putnbr_base(40, "poneyvif");
// 	printf("\n");
// 	ft_putnbr_base(894867, "0123456789");
// 	printf("\n");
// 	ft_putnbr_base(53, "0123456789abcdef");
// 	return (0);
// }
