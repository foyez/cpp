/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:26:09 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 20:59:08 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>

typedef struct s_rules
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	time_t			start_time;
	int				someone_died;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*fork_mutexes;
	struct s_philo	*philos;
}					t_rules;

typedef struct s_philo
{
	int				id;
	int				meals_eaten_count;
	time_t			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}					t_philo;

#endif
