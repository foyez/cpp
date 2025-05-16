/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:32:40 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/17 01:03:11 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	parse_op(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(op, "pa\n", 3))
		return (pa(a, b, 0), 1);
	if (!ft_strncmp(op, "pb\n", 3))
		return (pb(a, b, 0), 1);
	if (!ft_strncmp(op, "sa\n", 3))
		return (sa(a, 0), 1);
	if (!ft_strncmp(op, "sb\n", 3))
		return (sb(b, 0), 1);
	if (!ft_strncmp(op, "ss\n", 3))
		return (ss(a, b, 0), 1);
	if (!ft_strncmp(op, "ra\n", 3))
		return (ra(a, 0), 1);
	if (!ft_strncmp(op, "rb\n", 3))
		return (rb(b, 0), 1);
	if (!ft_strncmp(op, "rr\n", 3))
		return (rr(a, b, 0), 1);
	if (!ft_strncmp(op, "rra\n", 4))
		return (rra(a, 0), 1);
	if (!ft_strncmp(op, "rrb\n", 4))
		return (rrb(b, 0), 1);
	if (!ft_strncmp(op, "rrr\n", 4))
		return (rrr(a, b, 0), 1);
	return (0);
}

void	checker(t_stack *a, t_stack *b)
{
	char		*line;
	const int	input_fd = 0;

	line = get_next_line(input_fd);
	while (line)
	{
		if (!parse_op(line, a, b))
			return (free(line), ft_error());
		free(line);
		line = get_next_line(input_fd);
	}
	if (is_sorted(a) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
