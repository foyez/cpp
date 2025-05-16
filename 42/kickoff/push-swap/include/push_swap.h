/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:06 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 13:01:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/include/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// parse & validate arguments
int					count_numbers(char **argv, int argc);
int					fill_numbers(char **argv, int argc, int *arr);
int					*parse_args(char **inputs, int input_count, int *arr,
						int *n);
// stack
void				init_stack(t_stack *s);
void				push_stack(t_stack *s, int val);
t_node				*pop_stack(t_stack *s);
void				free_stack(t_stack *s);
// void				print_stack(t_stack *s);
// rules
void				sa(t_stack *a, int print);
void				sb(t_stack *b, int print);
void				ss(t_stack *a, t_stack *b, int print);
void				pa(t_stack *a, t_stack *b, int print);
void				pb(t_stack *b, t_stack *a, int print);
void				ra(t_stack *a, int print);
void				rb(t_stack *b, int print);
void				rr(t_stack *a, t_stack *b, int print);
void				rra(t_stack *a, int print);
void				rrb(t_stack *b, int print);
void				rrr(t_stack *a, t_stack *b, int print);
// sorting
void				sort(t_stack *a, t_stack *b);
int					is_median(t_stack *s, int val);
int					get_median(t_stack *s);
int					get_rotation_cost(t_stack *s, int index);
int					get_combined_rotation_cost(t_stack *src, t_stack *dst,
						int index);
// int					calc_move_cost(t_stack *src, t_stack *dst, int index);
t_node				*get_optimal_target(t_stack *src, t_stack *dst);
void				transfer_back_to_a(t_stack *a, t_stack *b);
void				rotate_min_to_top(t_stack *s, void (*r)(t_stack *, int),
						void (*rr)(t_stack *, int));
int					is_sorted(t_stack *s);
// utils
void				ft_printf_if(const char *s, int print);
void				ft_error(void);
int					is_space(char c);
int					ft_min(int n1, int n2);
int					ft_max(int n1, int n2);
int					ft_abs(int n);
int					get_node_pos(t_stack *s, int value);
t_node				*get_node_at(t_stack *s, int index);
t_node				*get_min(t_stack *s);
int					get_min_above_pos(t_stack *s, int num);
int					get_min_pos(t_stack *s);
t_node				*get_max(t_stack *s);
int					get_dst_pos(t_stack *dst, t_node *target);

#endif
