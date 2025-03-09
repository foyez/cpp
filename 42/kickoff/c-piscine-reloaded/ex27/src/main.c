/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:02:56 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/08 12:28:18 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error("File name missing.");
	else if (argc > 2)
		ft_error("Too many arguments.");
	else if (!ft_display_file(argv[1]))
		ft_error("Cannot read file.");
	return (0);
}
