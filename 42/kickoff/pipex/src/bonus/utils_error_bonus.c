/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:15:08 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/31 23:47:22 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_usage_warning(const char *cmd, int is_here_doc)
{
	ft_putstr_fd(YELLOW "Usage: ", 2);
	ft_putstr_fd(cmd, 2);
	if (is_here_doc)
		ft_putstr_fd(" here_doc LIMIT", 2);
	else
		ft_putstr_fd(" infile", 2);
	ft_putstr_fd(" cmd1 cmd2 outfile\n" RESET, 2);
}

void	ft_not_found_err(const char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}
