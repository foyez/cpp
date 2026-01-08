/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:19:01 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/04 18:52:47 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000));
}

void	smart_sleep(int ms)
{
	time_t	start;

	start = timestamp_ms();
	while (timestamp_ms() - start < ms)
		usleep(100);
}

void	print_action(t_philo *philo, const char *msg)
{
	time_t	now;

	now = timestamp_ms() - philo->cfg->start_time;
	sem_wait(philo->cfg->sem_log);
	printf("%ld %d %s\n", now, philo->id, msg);
	sem_post(philo->cfg->sem_log);
}

void	cleanup_child(t_philo *philo, t_config *cfg)
{
	if (cfg)
	{
		sem_close(cfg->sem_log);
		sem_close(cfg->sem_forks);
		free(cfg->philo_pids);
	}
	if (philo)
		free(philo);
}
