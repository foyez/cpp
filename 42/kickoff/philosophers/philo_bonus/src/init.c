/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:12:14 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:08:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_config *cfg)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_log");
	cfg->sem_forks = sem_open("/sem_forks", O_CREAT, 0644,
			cfg->number_of_philos);
	if (cfg->sem_forks == SEM_FAILED)
		return (0);
	cfg->sem_log = sem_open("/sem_log", O_CREAT, 0644, 1);
	if (cfg->sem_log == SEM_FAILED)
	{
		sem_close(cfg->sem_forks);
		sem_unlink("/sem_forks");
		return (0);
	}
	return (1);
}

void	cleanup_all(t_config *cfg)
{
	if (cfg->sem_forks)
	{
		sem_close(cfg->sem_forks);
		sem_unlink("/sem_forks");
	}
	if (cfg->sem_log)
	{
		sem_close(cfg->sem_log);
		sem_unlink("/sem_log");
	}
	free(cfg->philo_pids);
}
