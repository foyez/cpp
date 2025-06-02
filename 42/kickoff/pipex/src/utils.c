/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:10:17 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/31 23:47:35 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

void	pipex_perror(const char *context)
{
	ft_putstr_fd("pipex: ", 2);
	perror(context);
}

void	exit_with_errno(void)
{
	int	exitcode;

	exitcode = 1;
	if (errno == EACCES)
		exitcode = 126;
	else if (errno == ENOENT)
		exitcode = 127;
	exit(exitcode);
}

void	ft_usage_warning(const char *cmd)
{
	ft_putstr_fd(YELLOW "Usage: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" infile cmd1 cmd2 outfile\n" RESET, 2);
}

void	ft_not_found_err(const char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}
