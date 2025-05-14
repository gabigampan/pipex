/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:18 by fragamez          #+#    #+#             */
/*   Updated: 2025/02/12 16:39:55 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_cmd_path(char *argv, char **path)
{
	int		i;
	char	*temp;
	char	**cmd;
	char	*cmd_and_path;

	i = 0;
	cmd = ft_split(argv, ' ');
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_and_path = ft_strjoin(temp, cmd[0]);
		if (access(cmd_and_path, X_OK) == 0)
		{
			ft_free_split(cmd);
			return (cmd_and_path);
		}
		free(cmd_and_path);
		i++;
	}
	cmd_and_path = ft_strdup(cmd[0]);
	ft_free_split(cmd);
	return (cmd_and_path);
}

char	**ft_get_paths(char **env)
{
	int		i;
	char	*full_path;
	char	**path_splitted;

	i = 0;
	full_path = NULL;
	while (env[i] && !full_path)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			full_path = ft_strdup(env[i] + 5);
		}
		i++;
	}
	if (!full_path)
	{
		ft_error_pipex("Error PATH variable not found in env");
	}
	path_splitted = ft_split(full_path, ':');
	if (!path_splitted)
	{
		ft_error_pipex("Error to split PATH variable");
	}
	return (path_splitted);
}
