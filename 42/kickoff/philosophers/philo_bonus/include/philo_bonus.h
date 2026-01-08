/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:30 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/04 18:53:04 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_config
{
	int			number_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_required;
	time_t		start_time;

	sem_t		*sem_forks;
	sem_t		*sem_log;

	pid_t		*philo_pids;
}				t_config;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	time_t		last_meal;
	t_config	*cfg;
}				t_philo;

// utils
long			timestamp_ms(void);
void			smart_sleep(int ms);
void			print_action(t_philo *philo, const char *msg);

// core
int				parse_args(int argc, char **argv, t_config *cfg);
int				init_semaphores(t_config *cfg);
void			cleanup_all(t_config *cfg);
int				launch_philos(t_config *cfg);
void			wait_until_done_or_die(t_config *cfg);

// philo behavior
void			philo_process(t_config *cfg, int id);
void			*monitor_death(void *arg);
void			take_forks(t_philo *philo);
void			put_forks(t_philo *philo);
void			eat(t_philo *philo);
void			sleep_philo(t_philo *philo);
void			think(t_philo *philo, int silent);
void			cleanup_child(t_philo *philo, t_config *cfg);

#endif
