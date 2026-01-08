/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:30 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:05:48 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./types.h"

int		parse_args(int argc, char **argv, t_rules *rules);
int		init_rules(t_rules *rules);
int		init_philos(t_rules *rules);
int		start_simulation(t_rules *rules);
int		is_simulation_over(t_rules *rules);
void	exit_simulation(t_rules *rules);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	put_forks(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo, int silent);
int		check_philo_death(t_philo *philo);

void	ft_putstr(char *s, int fd);
time_t	timestamp_ms(void);
void	safe_print(t_philo *philo, const char *msg);
void	smart_sleep(t_rules *rules, int sleep_time);
void	cleanup_rules(t_rules *rules, int no_of_forks_init);
void	cleanup_philos(t_rules *rules, int no_of_philos_init);
void	delay_to_start(time_t start_time);

#endif
