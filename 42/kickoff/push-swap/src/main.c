/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:03:14 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 02:01:20 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// display "Error" followed by an ’\n’ on the standard error if
// some arguments not being integers,
// some arguments exceeding the integer limits (INT_MAX or INT_MIN acceptable),
// the presence of duplicates
// arg: 2 3 4 or "2 3 4" is acceptable
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
		if (!is_sorted(&a))
			sort(&a, &b);
		free_stack(&a);
		free_stack(&b);
		free(arr);
	}
	return (0);
}
