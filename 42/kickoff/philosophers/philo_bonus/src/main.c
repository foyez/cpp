/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:06 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 21:08:45 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (!parse_args(argc, argv, &cfg))
		return (1);
	if (!init_semaphores(&cfg))
		return (printf("Error: Failed to initialize semaphores\n"), 1);
	if (!launch_philos(&cfg))
		return (printf("Error: Failed to launch philosophers\n"), 1);
	wait_until_done_or_die(&cfg);
	cleanup_all(&cfg);
	return (0);
}
