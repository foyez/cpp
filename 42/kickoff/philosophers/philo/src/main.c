/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:06 by kaahmed           #+#    #+#             */
/*   Updated: 2025/08/03 20:59:50 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (!parse_args(argc, argv, &rules))
		return (1);
	if (!init_rules(&rules))
	{
		ft_putstr("Failed to initialize rules\n", 2);
		return (1);
	}
	if (!init_philos(&rules))
	{
		cleanup_rules(&rules, rules.number_of_philos);
		ft_putstr("Failed to initialize philos\n", 2);
		return (1);
	}
	if (!start_simulation(&rules))
	{
		cleanup_rules(&rules, rules.number_of_philos);
		cleanup_philos(&rules, rules.number_of_philos);
		ft_putstr("Failed to start simulation\n", 2);
		return (1);
	}
	exit_simulation(&rules);
	return (0);
}
