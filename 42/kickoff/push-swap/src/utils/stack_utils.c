/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:55:32 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:36:18 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_stack *s, int value)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = s->top;
	while (cur)
	{
		if (cur->data == value)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}

t_node	*get_node_at(t_stack *s, int index)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = s->top;
	while (cur && i < index)
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}

t_node	*get_min(t_stack *s)
{
	t_node	*min;
	t_node	*cur;

	min = s->top;
	cur = s->top;
	while (cur)
	{
		if (cur->data < min->data)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

int	get_min_above_pos(t_stack *s, int num)
{
	int		i;
	int		pos;
	int		min_above;
	t_node	*cur;

	i = 0;
	pos = -1;
	min_above = INT_MAX;
	cur = s->top;
	while (cur)
	{
		if (cur->data > num && cur->data < min_above)
		{
			min_above = cur->data;
			pos = i;
		}
		i++;
		cur = cur->next;
	}
	if (pos == -1)
		return (get_min_pos(s));
	return (pos);
}

t_node	*get_max(t_stack *s)
{
	t_node	*max;
	t_node	*cur;

	max = s->top;
	cur = s->top;
	while (cur)
	{
		if (cur->data > max->data)
			max = cur;
		cur = cur->next;
	}
	return (max);
}
