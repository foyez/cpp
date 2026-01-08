/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:06:16 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 20:59:46 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strtoi(const char *s, int *result)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (!is_valid_number(s))
		return (0);
	while (s[i])
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	*result = (int)num;
	return (1);
}

int	parse_args(int argc, char **argv, t_rules *rules)
{
	if (argc < 5 || argc > 6)
		return (ft_putstr("Usage: ./philo nop ttd tte tts [must_eat]\n", 2), 0);
	if (!ft_strtoi(argv[1], &rules->number_of_philos) || !ft_strtoi(argv[2],
			&rules->time_to_die) || !ft_strtoi(argv[3], &rules->time_to_eat)
		|| !ft_strtoi(argv[4], &rules->time_to_sleep))
	{
		ft_putstr("Invalid arguments\n", 2);
		return (0);
	}
	rules->meals_required = -1;
	if (argc == 6 && !ft_strtoi(argv[5], &rules->meals_required))
	{
		ft_putstr("Invalid must_eat argument\n", 2);
		return (0);
	}
	if (rules->number_of_philos <= 0 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0 || (argc == 6
			&& rules->meals_required <= 0))
	{
		ft_putstr("Arguments must be positive\n", 2);
		return (0);
	}
	return (1);
}
