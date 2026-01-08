/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:19:04 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:07:06 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *arg);
static void	*monitor_routine(void *arg);

int	start_simulation(t_rules *rules)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	while (++i < rules->number_of_philos)
	{
		if (pthread_create(&rules->philos[i].thread, NULL, philo_routine,
				&rules->philos[i]) != 0)
			return (0);
	}
	if (pthread_create(&monitor_thread, NULL, monitor_routine, rules) != 0)
		return (0);
	if (pthread_join(monitor_thread, NULL) != 0)
		return (0);
	return (1);
}

static void	*single_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo, "has taken a fork");
	smart_sleep(philo->rules, philo->rules->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	delay_to_start(philo->rules->start_time);
	if (philo->rules->number_of_philos == 1)
		return (single_philo_routine(philo));
	if (philo->id % 2 == 0)
		think(philo, 1);
	while (!is_simulation_over(philo->rules))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
		think(philo, 0);
	}
	return (NULL);
}

static int	is_all_philos_ate_enough(t_rules *rules)
{
	int	i;

	if (rules->meals_required == -1)
		return (0);
	i = -1;
	while (++i < rules->number_of_philos)
	{
		pthread_mutex_lock(&rules->philos[i].meal_mutex);
		if (rules->philos[i].meals_eaten_count < rules->meals_required)
		{
			pthread_mutex_unlock(&rules->philos[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&rules->philos[i].meal_mutex);
	}
	pthread_mutex_lock(&rules->death_mutex);
	rules->someone_died = 1;
	pthread_mutex_unlock(&rules->death_mutex);
	return (1);
}

static void	*monitor_routine(void *arg)
{
	int		i;
	t_rules	*rules;

	rules = (t_rules *)arg;
	delay_to_start(rules->start_time);
	while (!is_simulation_over(rules))
	{
		i = -1;
		while (++i < rules->number_of_philos)
		{
			if (check_philo_death(&rules->philos[i]))
				return (NULL);
		}
		if (is_all_philos_ate_enough(rules))
			break ;
	}
	return (NULL);
}
