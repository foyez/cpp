/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:50:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 12:59:45 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_node	*cur;

	cur = s->top;
	while (cur && cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	get_min_pos(t_stack *s)
{
	int		i;
	int		pos;
	int		min;
	t_node	*cur;

	i = 0;
	pos = 0;
	min = s->top->data;
	cur = s->top;
	while (cur)
	{
		if (cur->data < min)
		{
			min = cur->data;
			pos = i;
		}
		i++;
		cur = cur->next;
	}
	return (pos);
}

int	get_dst_pos(t_stack *dst, t_node *target)
{
	int	dst_pos;

	if (target->data < get_min(dst)->data || target->data > get_max(dst)->data)
		dst_pos = get_min_pos(dst);
	else
		dst_pos = get_min_above_pos(dst, target->data);
	return (dst_pos);
}
