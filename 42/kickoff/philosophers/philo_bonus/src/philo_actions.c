/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:20:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/04 18:55:17 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	if (timestamp_ms() - philo->last_meal >= philo->cfg->time_to_die)
	{
		sem_wait(philo->cfg->sem_log);
		printf("%ld %d died\n", timestamp_ms() - philo->cfg->start_time,
			philo->id);
		cleanup_child(philo, philo->cfg);
		exit(1);
	}
	sem_wait(philo->cfg->sem_forks);
	print_action(philo, "has taken a fork");
	sem_wait(philo->cfg->sem_forks);
	print_action(philo, "has taken a fork");
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->cfg->sem_forks);
	sem_post(philo->cfg->sem_forks);
}

void	eat(t_philo *philo)
{
	philo->last_meal = timestamp_ms();
	print_action(philo, "is eating");
	smart_sleep(philo->cfg->time_to_eat);
	philo->meals_eaten++;
}

void	sleep_philo(t_philo *philo)
{
	print_action(philo, "is sleeping");
	smart_sleep(philo->cfg->time_to_sleep);
}

void	think(t_philo *philo, int silent)
{
	time_t	time_since_last_meal;
	time_t	time_to_think;

	time_since_last_meal = timestamp_ms() - philo->last_meal;
	time_to_think = (philo->cfg->time_to_die - time_since_last_meal
			- philo->cfg->time_to_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	else if (time_to_think == 0 && silent == 1)
		time_to_think = 1;
	else if (time_to_think > 600)
		time_to_think = 200;
	if (!silent)
		print_action(philo, "is thinking");
	smart_sleep(time_to_think);
}
