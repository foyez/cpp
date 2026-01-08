/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:03:39 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:07:11 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_simulation_over(t_rules *rules)
{
	int	status;

	pthread_mutex_lock(&rules->death_mutex);
	status = rules->someone_died;
	pthread_mutex_unlock(&rules->death_mutex);
	return (status);
}

void	cleanup_rules(t_rules *rules, int no_of_forks_init)
{
	int	i;

	if (rules->fork_mutexes)
	{
		i = -1;
		while (++i < no_of_forks_init)
			pthread_mutex_destroy(&rules->fork_mutexes[i]);
		free(rules->fork_mutexes);
	}
	pthread_mutex_destroy(&rules->log_mutex);
	pthread_mutex_destroy(&rules->death_mutex);
}

void	cleanup_philos(t_rules *rules, int no_of_philos_init)
{
	int	i;

	if (rules->philos)
	{
		i = -1;
		while (++i < no_of_philos_init)
			pthread_mutex_destroy(&rules->philos[i].meal_mutex);
		free(rules->philos);
	}
}

void	exit_simulation(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philos)
		pthread_join(rules->philos[i].thread, NULL);
	cleanup_rules(rules, rules->number_of_philos);
	cleanup_philos(rules, rules->number_of_philos);
}

int	check_philo_death(t_philo *philo)
{
	time_t	time_since_meal;
	time_t	time_since_start;

	pthread_mutex_lock(&philo->meal_mutex);
	time_since_meal = timestamp_ms() - philo->last_meal_time;
	if (time_since_meal >= philo->rules->time_to_die)
	{
		pthread_mutex_lock(&philo->rules->death_mutex);
		if (!philo->rules->someone_died)
			philo->rules->someone_died = 1;
		pthread_mutex_unlock(&philo->rules->death_mutex);
		time_since_start = timestamp_ms() - philo->rules->start_time;
		pthread_mutex_lock(&philo->rules->log_mutex);
		printf("%ld %d died\n", time_since_start, philo->id);
		pthread_mutex_unlock(&philo->rules->log_mutex);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}
