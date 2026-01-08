/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:20:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 20:59:54 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	safe_print(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = timestamp_ms();
	philo->meals_eaten_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	safe_print(philo, "is eating");
	smart_sleep(philo->rules, philo->rules->time_to_eat);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_philo(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	smart_sleep(philo->rules, philo->rules->time_to_sleep);
}

void	think(t_philo *philo, int silent)
{
	time_t	time_since_last_meal;
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_mutex);
	time_since_last_meal = timestamp_ms() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	time_to_think = (philo->rules->time_to_die - time_since_last_meal
			- philo->rules->time_to_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	else if (time_to_think == 0 && silent == 1)
		time_to_think = 1;
	else if (time_to_think > 600)
		time_to_think = 200;
	if (silent == 0)
		safe_print(philo, "is thinking");
	smart_sleep(philo->rules, time_to_think);
}
