/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:04:49 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/11 20:06:14 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_median(t_stack *s, int val)
{
	int		higher;
	int		lower;
	t_node	*cur;

	higher = 0;
	lower = 0;
	cur = s->top;
	while (cur)
	{
		if (cur->data > val)
			higher++;
		else if (cur->data < val)
			lower++;
		cur = cur->next;
	}
	return ((higher - lower) >= -1 && (higher - lower) <= 1);
}

int	get_median(t_stack *s)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		if (is_median(s, cur->data))
			return (cur->data);
		cur = cur->next;
	}
	return (-1);
}
