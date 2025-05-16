/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:30:02 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 01:24:48 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		*arr;
	int		n;
	t_stack	a;
	t_stack	b;
	int		i;

	arr = NULL;
	if (argc > 1)
	{
		arr = parse_args(argv + 1, argc - 1, arr, &n);
		if (!arr)
			return (ft_error(), 1);
		init_stack(&a);
		init_stack(&b);
		i = n;
		while (--i >= 0)
			push_stack(&a, arr[i]);
		checker(&a, &b);
		free_stack(&a);
		free_stack(&b);
		free(arr);
	}
	return (0);
}
