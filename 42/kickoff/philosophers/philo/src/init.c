/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:12:14 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:00:22 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_rules(t_rules *rules)
{
	int		i;
	time_t	delay_ms;

	delay_ms = rules->number_of_philos * 2 * 10;
	rules->start_time = timestamp_ms() + delay_ms;
	rules->someone_died = 0;
	rules->fork_mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* rules->number_of_philos);
	if (!rules->fork_mutexes)
		return (0);
	i = -1;
	while (++i < rules->number_of_philos)
	{
		if (pthread_mutex_init(&rules->fork_mutexes[i], NULL) != 0)
			return (cleanup_rules(rules, i), 0);
	}
	if (pthread_mutex_init(&rules->log_mutex, NULL) != 0)
		return (cleanup_rules(rules, i), 0);
	if (pthread_mutex_init(&rules->death_mutex, NULL) != 0)
		return (cleanup_rules(rules, i), 0);
	return (1);
}

static void	assing_forks(t_philo *philo, t_rules *rules, int i)
{
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &rules->fork_mutexes[i];
		philo->right_fork = &rules->fork_mutexes[(i + 1)
			% rules->number_of_philos];
	}
	else
	{
		philo->left_fork = &rules->fork_mutexes[(i + 1)
			% rules->number_of_philos];
		philo->right_fork = &rules->fork_mutexes[i];
	}
}

int	init_philos(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	rules->philos = (t_philo *)malloc(sizeof(t_philo)
			* rules->number_of_philos);
	if (!rules->philos)
		return (0);
	i = -1;
	while (++i < rules->number_of_philos)
	{
		philo = &rules->philos[i];
		philo->id = i + 1;
		philo->meals_eaten_count = 0;
		philo->last_meal_time = rules->start_time;
		if (pthread_mutex_init(&philo->meal_mutex, NULL) != 0)
			return (cleanup_philos(rules, i), 0);
		philo->rules = rules;
		assing_forks(philo, rules, i);
	}
	return (1);
}
