/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:51:48 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:05:47 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !s->top || !s->top->next)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
}

void	sa(t_stack *a, int print)
{
	swap(a);
	ft_printf_if("sa\n", print);
}

void	sb(t_stack *b, int print)
{
	swap(b);
	ft_printf_if("sb\n", print);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	swap(a);
	swap(b);
	ft_printf_if("ss\n", print);
}
