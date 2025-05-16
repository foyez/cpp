/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:02:46 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 13:03:58 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(t_stack *s, int position)
{
	int	size;
	int	mid;

	size = s->size;
	mid = size / 2;
	if (position <= mid)
		return (position);
	return (-(size - position));
}

int	get_combined_rotation_cost(t_stack *src, t_stack *dst, int target_pos)
{
	int		src_rot;
	t_node	*target;
	int		dst_pos;
	int		dst_rot;

	src_rot = get_rotation_cost(src, target_pos);
	target = get_node_at(src, target_pos);
	dst_pos = get_dst_pos(dst, target);
	dst_rot = get_rotation_cost(dst, dst_pos);
	if (src_rot > 0 && dst_rot > 0)
		return (ft_min(src_rot, dst_rot));
	if (src_rot < 0 && dst_rot < 0)
		return (ft_max(src_rot, dst_rot));
	return (0);
}

static int	calc_move_cost(t_stack *src, t_stack *dst, int target_pos)
{
	int		cost;
	t_node	*target;
	int		dst_pos;

	cost = ft_abs(get_rotation_cost(src, target_pos));
	target = get_node_at(src, target_pos);
	dst_pos = get_dst_pos(dst, target);
	cost += ft_abs(get_rotation_cost(dst, dst_pos));
	cost -= ft_abs(get_combined_rotation_cost(src, dst, target_pos));
	return (cost + 1);
}

t_node	*get_optimal_target(t_stack *src, t_stack *dst)
{
	t_node	*cur;
	t_node	*target;
	int		min_cost;
	int		i;
	int		cost;

	cur = src->top;
	target = src->top;
	min_cost = INT_MAX;
	i = 0;
	while (cur)
	{
		cost = calc_move_cost(src, dst, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			target = cur;
		}
		cur = cur->next;
		i++;
	}
	return (target);
}
