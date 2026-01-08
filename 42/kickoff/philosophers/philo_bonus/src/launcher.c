/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:50:28 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/04 18:58:26 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

void	philo_process(t_config *cfg, int id)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		cleanup_child(philo, cfg);
		exit(1);
	}
	philo->cfg = cfg;
	philo->id = id + 1;
	philo->meals_eaten = 0;
	philo->last_meal = cfg->start_time;
	pthread_create(&monitor, NULL, monitor_death, philo);
	pthread_detach(monitor);
	if (philo->id % 2 == 0)
		think(philo, 1);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		if (cfg->meals_required != -1
			&& philo->meals_eaten >= cfg->meals_required)
		{
			cleanup_child(philo, cfg);
			exit(0);
		}
		sleep_philo(philo);
		think(philo, 0);
	}
}

int	launch_philos(t_config *cfg)
{
	int		i;
	pid_t	pid;

	cfg->philo_pids = malloc(sizeof(pid_t) * cfg->number_of_philos);
	if (!cfg->philo_pids)
		return (0);
	cfg->start_time = timestamp_ms();
	i = -1;
	while (++i < cfg->number_of_philos)
	{
		pid = fork();
		if (pid < 0)
			return (0);
		if (pid == 0)
			philo_process(cfg, i);
		else
			cfg->philo_pids[i] = pid;
	}
	return (1);
}

void	wait_until_done_or_die(t_config *cfg)
{
	int	status;
	int	count;
	int	i;

	count = 0;
	while (count < cfg->number_of_philos)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				i = -1;
				while (++i < cfg->number_of_philos)
					kill(cfg->philo_pids[i], SIGTERM);
				break ;
			}
			count++;
		}
	}
}
