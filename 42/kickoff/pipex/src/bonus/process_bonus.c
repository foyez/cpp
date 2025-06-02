/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:46:22 by kaahmed           #+#    #+#             */
/*   Updated: 2025/06/02 16:26:10 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_shell_args(cmd);
	if (!args || !args[0])
		exit(1);
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		if (errno == EACCES)
		{
			pipex_perror(args[0]);
			free_args((void **)args);
			exit(126);
		}
		ft_not_found_err(args[0]);
		free_args((void **)args);
		exit(127);
	}
	execve(path, args, envp);
	pipex_perror(args[0]);
	free(path);
	free_args((void **)args);
	exit_with_errno();
}

void	childprocess(int i, char *cmd, t_pipex *p, char **envp)
{
	if (i == 0)
	{
		if (p->fd_in == -1)
			exit(1);
		dup2(p->fd_in, STDIN_FILENO);
	}
	else
		dup2(p->pipefds[p->read_pipe][0], STDIN_FILENO);
	if (i == p->cmd_cnt - 1)
	{
		if (p->fd_out == -1)
			exit(1);
		dup2(p->fd_out, STDOUT_FILENO);
	}
	else
		dup2(p->pipefds[p->write_pipe][1], STDOUT_FILENO);
	close_pipe_if(p->pipefds[p->read_pipe], i != 0);
	close_pipe_if(p->pipefds[p->write_pipe], i != p->cmd_cnt - 1);
	close_files(p->fd_in, p->fd_out);
	exec_command(cmd, envp);
}

int	waitforchildren(t_pipex *p)
{
	int	status;
	int	wstatus;

	status = 0;
	p->waited_pid = wait(&wstatus);
	while (p->waited_pid > 0)
	{
		if (p->waited_pid == p->last_pid && WIFEXITED(wstatus))
			status = WEXITSTATUS(wstatus);
		p->waited_pid = wait(&wstatus);
	}
	return (status);
}

int	parentprocess(t_pipex *p, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < p->cmd_cnt)
	{
		p->read_pipe = i % 2;
		p->write_pipe = (i + 1) % 2;
		if (i < p->cmd_cnt - 1 && pipe(p->pipefds[p->write_pipe]) == -1)
			return (pipex_perror("pipe"), 1);
		p->pid = fork();
		if (p->pid == -1)
			return (pipex_perror("fork"), 1);
		if (p->pid == 0)
			childprocess(i, argv[i + p->cmd_start], p, envp);
		else if (i == p->cmd_cnt - 1)
			p->last_pid = p->pid;
		close_pipe_if(p->pipefds[p->read_pipe], i != 0);
	}
	close_files(p->fd_in, p->fd_out);
	return (waitforchildren(p));
}
