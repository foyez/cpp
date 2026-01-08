/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:19:01 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:02:44 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	ft_putstr(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

time_t	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	safe_print(t_philo *philo, const char *msg)
{
	time_t	time_since_start;

	pthread_mutex_lock(&philo->rules->log_mutex);
	if (!is_simulation_over(philo->rules))
	{
		time_since_start = timestamp_ms() - philo->rules->start_time;
		printf("%ld %d %s\n", time_since_start, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->rules->log_mutex);
}

void	smart_sleep(t_rules *rules, int sleeping_time)
{
	time_t	wake_up;

	wake_up = timestamp_ms() + sleeping_time;
	while (timestamp_ms() < wake_up)
	{
		if (is_simulation_over(rules))
			break ;
		usleep(100);
	}
}

void	delay_to_start(time_t start_time)
{
	while (timestamp_ms() < start_time)
		usleep(50);
}
