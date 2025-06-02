/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:55:26 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/31 23:36:36 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			free(args);
			exit(126);
		}
		ft_not_found_err(args[0]);
		free(args);
		exit(127);
	}
	execve(path, args, envp);
	pipex_perror(args[0]);
	free(path);
	free(args);
	exit_with_errno();
}

void	child1(int pipefd[2], char *infile, char *cmd, char **envp)
{
	int	fd_in;

	fd_in = open(infile, O_RDONLY);
	if (fd_in < 0)
	{
		pipex_perror(infile);
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	exec_command(cmd, envp);
}

void	child2(int pipefd[2], char *outfile, char *cmd, char **envp)
{
	int	fd_out;

	fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		pipex_perror(outfile);
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_out);
	exec_command(cmd, envp);
}

int	parent_process(int pipefd[2], pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	if (WIFEXITED(status1))
		return (WEXITSTATUS(status1));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_usage_warning(argv[0]);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		child1(pipefd, argv[1], argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		child2(pipefd, argv[4], argv[3], envp);
	return (parent_process(pipefd, pid1, pid2));
}
