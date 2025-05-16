/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:25:42 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 01:49:57 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

int	is_empty(t_stack *s)
{
	return (s->top == NULL);
}

void	push_stack(t_stack *s, int val)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = val;
	new_node->next = s->top;
	s->top = new_node;
	s->size++;
}

t_node	*pop_stack(t_stack *s)
{
	t_node	*top;

	if (!s->top)
		return (NULL);
	top = s->top;
	s->top = top->next;
	s->size--;
	top->next = NULL;
	return (top);
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (!is_empty(s))
	{
		tmp = pop_stack(s);
		free(tmp);
	}
}

// void	print_stack(t_stack *s)
// {
// 	t_node	*cur;

// 	cur = s->top;
// 	ft_printf("stack: ");
// 	while (cur)
// 	{
// 		ft_printf("%d ", cur->data);
// 		cur = cur->next;
// 	}
// 	ft_printf("\n");
// }
