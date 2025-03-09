/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:36:19 by kaahmed           #+#    #+#             */
/*   Updated: 2025/03/08 12:59:33 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_display_file(const char *file_path)
{
	int		fd;
	int		bytes_read;
	char	buffer[1024];

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (bytes_read == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
