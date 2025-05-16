/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:17:14 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 21:25:10 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_combine_rotations(t_stack *src, t_stack *dst,
		t_node *target)
{
	int	target_pos;
	int	cost;

	target_pos = get_node_pos(src, target->data);
	cost = get_combined_rotation_cost(src, dst, target_pos);
	while (cost != 0)
	{
		if (cost > 0)
		{
			rr(src, dst, 1);
			cost--;
		}
		else
		{
			rrr(src, dst, 1);
			cost++;
		}
	}
}

static void	rotate_to_top(t_stack *s, t_node *target, void (*r)(t_stack *, int),
		void (*rr)(t_stack *, int))
{
	int	target_pos;
	int	cost;

	target_pos = get_node_pos(s, target->data);
	cost = get_rotation_cost(s, target_pos);
	while (cost != 0)
	{
		if (cost > 0)
		{
			r(s, 1);
			cost--;
		}
		else
		{
			rr(s, 1);
			cost++;
		}
	}
}

static void	prepare_dest_stack(t_stack *dst, t_node *target,
		void (*r)(t_stack *, int), void (*rr)(t_stack *, int))
{
	int	dst_pos;
	int	cost;

	dst_pos = get_dst_pos(dst, target);
	cost = get_rotation_cost(dst, dst_pos);
	while (cost != 0)
	{
		if (cost > 0)
		{
			r(dst, 1);
			cost--;
		}
		else
		{
			rr(dst, 1);
			cost++;
		}
	}
}

void	rotate_min_to_top(t_stack *s, void (*r)(t_stack *, int),
		void (*rr)(t_stack *, int))
{
	int	target_pos;
	int	cost;

	target_pos = get_min_pos(s);
	cost = get_rotation_cost(s, target_pos);
	while (cost != 0)
	{
		if (cost > 0)
		{
			r(s, 1);
			cost--;
		}
		else
		{
			rr(s, 1);
			cost++;
		}
	}
}

void	transfer_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;

	while (b->size > 0)
	{
		target = get_optimal_target(b, a);
		execute_combine_rotations(b, a, target);
		rotate_to_top(b, target, rb, rrb);
		prepare_dest_stack(a, target, ra, rra);
		pa(a, b, 1);
	}
}
