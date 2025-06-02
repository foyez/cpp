/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:18 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/02 16:34:31 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	handle_line(char *line, const char *limiter)
{
	if (!line)
	{
		ft_putstr_fd("Stopped (EOF) before limiter was found\n", 2);
		return (0);
	}
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& line[ft_strlen(limiter)] == '\n')
	{
		free(line);
		return (0);
	}
	return (1);
}

void	heredoc_childprocess(const char *limiter, const char *tmpfile)
{
	char	*line;
	int		fd;

	fd = open_file(tmpfile, 2);
	if (fd < 0)
		exit(1);
	line = NULL;
	while (1)
	{
		ft_putstr_fd("heredoc> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!handle_line(line, limiter))
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
	exit(0);
}

void	read_heredoc_input(const char *limiter, int *fd_in)
{
	const char	*tmpfile = ".heredoc_tmp";
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		pipex_perror("fork");
		exit(1);
	}
	if (pid == 0)
		heredoc_childprocess(limiter, tmpfile);
	waitpid(pid, NULL, 0);
	*fd_in = open(tmpfile, O_RDONLY);
	if (*fd_in < 0)
	{
		pipex_perror(tmpfile);
		exit(1);
	}
	unlink(tmpfile);
}
