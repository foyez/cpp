/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:23 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:03:41 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int print)
{
	t_node	*top_b;

	top_b = pop_stack(b);
	if (!top_b)
		return ;
	top_b->next = a->top;
	a->top = top_b;
	a->size++;
	ft_printf_if("pa\n", print);
}

void	pb(t_stack *a, t_stack *b, int print)
{
	t_node	*top_a;

	top_a = pop_stack(a);
	if (!top_a)
		return ;
	top_a->next = b->top;
	b->top = top_a;
	b->size++;
	ft_printf_if("pb\n", print);
}
