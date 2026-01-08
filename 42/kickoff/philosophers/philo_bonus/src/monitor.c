/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:56:39 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/04 18:54:43 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *arg)
{
	t_philo	*philo;
	time_t	now;

	philo = (t_philo *)arg;
	while (1)
	{
		now = timestamp_ms();
		if (now - philo->last_meal >= philo->cfg->time_to_die)
		{
			sem_wait(philo->cfg->sem_log);
			printf("%ld %d died\n", now - philo->cfg->start_time, philo->id);
			cleanup_child(philo, philo->cfg);
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}
