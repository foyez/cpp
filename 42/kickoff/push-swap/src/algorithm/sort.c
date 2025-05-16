/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:17:09 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/15 18:31:39 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->top->data;
	n2 = a->top->next->data;
	n3 = a->top->next->next->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a, 1);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a, 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a, 1);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

static void	sort_4(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = get_min_pos(a);
	if (min_pos == 1)
		ra(a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_pos == 3)
		rra(a, 1);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_3(a);
	pa(a, b, 1);
}

static void	sort_5(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = get_min_pos(a);
	if (min_pos == 1)
		ra(a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_pos == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (min_pos == 4)
		rra(a, 1);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_4(a, b);
	pa(a, b, 1);
}

static void	sort_large(t_stack *a, t_stack *b)
{
	int	median;

	median = get_median(a);
	while (a->size > 3)
	{
		pb(a, b, 1);
		if (b->top->data > median && a->size > 3)
			rb(b, 1);
	}
	sort_3(a);
	transfer_back_to_a(a, b);
	rotate_min_to_top(a, ra, rra);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a, 1);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		sort_large(a, b);
}
