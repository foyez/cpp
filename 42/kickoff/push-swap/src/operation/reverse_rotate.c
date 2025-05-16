/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:38:58 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:04:44 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = s->top;
	s->top = last;
}

void	rra(t_stack *a, int print)
{
	reverse_rotate(a);
	ft_printf_if("rra\n", print);
}

void	rrb(t_stack *b, int print)
{
	reverse_rotate(b);
	ft_printf_if("rrb\n", print);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf_if("rrr\n", print);
}
