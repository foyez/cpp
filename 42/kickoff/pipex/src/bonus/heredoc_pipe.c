/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:49 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/02 16:34:41 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_childprocess(int pipefd[2], const char *limiter)
{
	char	*line;

	line = NULL;
	while (1)
	{
		write(2, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_putstr_fd("Stopped (EOF) before limiter was found\n", 2);
			break ;
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
	exit(0);
}

void	read_heredoc_input(const char *limiter, int *fd_in)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		pipex_perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		pipex_perror("fork");
		exit(1);
	}
	if (pid == 0)
		heredoc_childprocess(pipefd, limiter);
	waitpid(pid, NULL, 0);
	*fd_in = pipefd[0];
	close(pipefd[1]);
}
