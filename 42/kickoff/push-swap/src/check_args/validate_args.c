/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:21:33 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/16 01:10:35 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_num(char *str, int *i, int *count)
{
	int	has_digit;

	if (str[*i] == '-' || str[*i] == '+')
	{
		(*i)++;
		if (!ft_isdigit(str[*i]))
			return (0);
	}
	has_digit = 0;
	while (ft_isdigit(str[*i]))
	{
		has_digit = 1;
		(*i)++;
	}
	if (has_digit)
		(*count)++;
	return (1);
}

static int	is_duplicate(int num, int arr[], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (num == arr[i])
			return (1);
	}
	return (0);
}

static int	my_atol(const char *str, int *i, int *num)
{
	long	l_num;
	int		sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!(ft_isdigit(str[*i])))
		return (-1);
	l_num = 0;
	while (ft_isdigit(str[*i]))
	{
		l_num = l_num * 10 + (str[*i] - '0');
		if ((sign == 1 && l_num > INT_MAX) || (sign == -1
				&& (-l_num < INT_MIN)))
			return (-1);
		(*i)++;
	}
	*num = (int)(l_num * sign);
	return (0);
}

int	count_numbers(char **inputs, int input_count)
{
	int		count;
	int		i;
	int		j;
	char	*trimmed;

	count = 0;
	i = -1;
	while (++i < input_count)
	{
		trimmed = ft_strtrim(inputs[i], " ");
		if (!trimmed || trimmed[0] == '\0')
			return (free(trimmed), -1);
		j = 0;
		while (trimmed[j])
		{
			while (is_space(trimmed[j]))
				j++;
			if (trimmed && !is_valid_num(trimmed, &j, &count))
				return (free(trimmed), -1);
			else if (trimmed[j] && !is_space(trimmed[j]))
				return (-1);
		}
		free(trimmed);
	}
	return (count);
}

int	fill_numbers(char **inputs, int input_count, int *arr)
{
	int	num;
	int	i;
	int	j;
	int	idx;

	i = -1;
	idx = 0;
	while (++i < input_count)
	{
		j = 0;
		while (inputs[i] && inputs[i][j])
		{
			while (is_space(inputs[i][j]))
				j++;
			if (!inputs[i][j])
				break ;
			if (my_atol(inputs[i], &j, &num) == -1)
				return (-1);
			if (is_duplicate(num, arr, idx))
				return (-1);
			arr[idx++] = num;
		}
	}
	return (0);
}
