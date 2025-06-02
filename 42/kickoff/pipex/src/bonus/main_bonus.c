/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:55:26 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/02 16:25:12 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(const char *filepath, int mode)
{
	int	fd;

	fd = -1;
	if (mode == 1)
		fd = open(filepath, O_RDONLY);
	else if (mode == 2)
		fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == 3)
		fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		pipex_perror(filepath);
	return (fd);
}

int	isvalid_args(int argc, char **argv, int *is_heredoc)
{
	*is_heredoc = argc >= 2 && ft_strncmp(argv[1], "here_doc", 8) == 0;
	if (*is_heredoc && argc < 6)
	{
		ft_usage_warning(argv[0], 1);
		return (0);
	}
	if (argc < 5)
	{
		ft_usage_warning(argv[0], 0);
		return (0);
	}
	return (1);
}

// N-1 pipes for N commands
// 1 pipe (|) for each connection between 2 commands
// each pipe: 2 fd, pipeds[0] read end, pipefds[1] write end
// fork() -> create a child process for each command
// dup2() -> set stdin/stdout for each command using pipes or file descriptors
// execve() -> replace the child process image with a new program
// here_doc -> read from stdin until the user type limiter
// and store in temp buffer (pipe)
// while outfile should be oppend in append mode
int	main(int argc, char **argv, char **envp)
{
	int		is_heredoc;
	t_pipex	p;

	if (!isvalid_args(argc, argv, &is_heredoc))
		return (1);
	p.cmd_start = 2;
	if (is_heredoc)
	{
		read_heredoc_input(argv[2], &p.fd_in);
		p.fd_out = open_file(argv[argc - 1], 3);
		p.cmd_start = 3;
	}
	else
	{
		p.fd_in = open_file(argv[1], 1);
		p.fd_out = open_file(argv[argc - 1], 2);
	}
	p.cmd_cnt = argc - p.cmd_start - 1;
	return (parentprocess(&p, argv, envp));
}
