/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:16:01 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/12 02:55:10 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(char **inputs, int input_count, int *arr, int *n)
{
	*n = count_numbers(inputs, input_count);
	if (*n == -1)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * *n);
	if (!arr)
		return (NULL);
	if (fill_numbers(inputs, input_count, arr) == -1)
		return (free(arr), NULL);
	return (arr);
}
