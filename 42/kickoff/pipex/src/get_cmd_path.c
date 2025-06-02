/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:10:28 by kaahmed           #+#    #+#             */
/*   Updated: 2025/05/29 15:47:36 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_executable(const char *path)
{
	if (access(path, X_OK) != 0)
	{
		errno = EACCES;
		return (0);
	}
	return (1);
}

char	*extract_path_env(char **envp)
{
	int		i;
	char	*path_env;

	path_env = "/usr/local/bin:/usr/bin:/bin";
	if (!envp)
		return (path_env);
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i])
		path_env = envp[i] + 5;
	return (path_env);
}

void	build_path(char *path, const char *dir, const char *cmd, size_t size)
{
	ft_strlcpy(path, dir, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, cmd, size);
}

char	*find_executable_path(char **dirs, const char *cmd)
{
	int		i;
	char	fullpath[1024];

	i = -1;
	while (dirs[++i])
	{
		build_path(fullpath, dirs[i], cmd, sizeof(fullpath));
		if (access(fullpath, F_OK) == 0)
		{
			if (!is_executable(fullpath))
				return (free_args(dirs), NULL);
			return (free_args(dirs), ft_strdup(fullpath));
		}
	}
	free_args(dirs);
	return (NULL);
}

char	*get_cmd_path(const char *cmd, char **envp)
{
	char	*path_env;
	char	**dirs;
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (!is_executable(cmd))
			return (NULL);
		return (ft_strdup(cmd));
	}
	path_env = extract_path_env(envp);
	dirs = ft_split(path_env, ':');
	if (!dirs)
		return (NULL);
	path = find_executable_path(dirs, cmd);
	if (!path)
	{
		errno = ENOENT;
		return (NULL);
	}
	return (path);
}
