/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:35:43 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:05:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	last = s->top;
	while (last->next)
		last = last->next;
	s->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *a, int print)
{
	rotate(a);
	ft_printf_if("ra\n", print);
}

void	rb(t_stack *b, int print)
{
	rotate(b);
	ft_printf_if("rb\n", print);
}

void	rr(t_stack *a, t_stack *b, int print)
{
	rotate(a);
	rotate(b);
	ft_printf_if("rr\n", print);
}
