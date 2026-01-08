/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:42:12 by kaahmed           #+#    #+#             */
/*   Updated: 2025/07/25 22:53:11 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5

typedef struct s_philo {
	int	id;
	pthread_t	thread;
}	t_philo;
t_philo	philos[N];
pthread_mutex_t	log_mutex;

void	safe_print(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&log_mutex);
	printf("%d %s\n", philo->id, msg);
	pthread_mutex_unlock(&log_mutex);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	safe_print(philo, "is thinking");
	usleep(100000);
	safe_print(philo, "is eating");
	usleep(100000);
	safe_print(philo, "is sleeping");
	return (NULL);
}

int main(void)
{
	int i;

	pthread_mutex_init(&log_mutex, NULL);
	i = -1;
	while (++i < N)
	{
		philos[i].id = i + 1;
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
		{
			perror("pthread_create failed");
			return (1);
		}
	}
	i = -1;
	while (++i < N)
		pthread_join(philos[i].thread, NULL);
	pthread_mutex_destroy(&log_mutex);
	return (0);
}
