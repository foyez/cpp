/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:06:16 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:08:23 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
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

int	parse_args(int argc, char **argv, t_config *cfg)
{
	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo nop ttd tte tts [must_eat]\n"), 0);
	if (!ft_strtoi(argv[1], &cfg->number_of_philos) || !ft_strtoi(argv[2],
			&cfg->time_to_die) || !ft_strtoi(argv[3], &cfg->time_to_eat)
		|| !ft_strtoi(argv[4], &cfg->time_to_sleep))
	{
		printf("Invalid arguments\n");
		return (0);
	}
	cfg->meals_required = -1;
	if (argc == 6 && !ft_strtoi(argv[5], &cfg->meals_required))
	{
		printf("Invalid must_eat argument\n");
		return (0);
	}
	if (cfg->number_of_philos <= 0 || cfg->time_to_die < 0
		|| cfg->time_to_eat < 0 || cfg->time_to_sleep < 0 || (argc == 6
			&& cfg->meals_required <= 0))
	{
		printf("Arguments must be positive\n");
		return (0);
	}
	return (1);
}
