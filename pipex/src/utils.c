/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:56 by fragamez          #+#    #+#             */
/*   Updated: 2025/05/14 18:13:56 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	operate_dup2(int fd_old, int fd_new)
{
	if (dup2(fd_old, fd_new) == -1)
	{
		ft_error_pipex("Dup2 Error");
	}
	close(fd_old);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clean_resources(int *pipe_fd, int fd_in, int fd_out)
{
	if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
	if (fd_in != -1)
		close(fd_in);
	if (fd_out != -1)
		close(fd_out);
}

void	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	char	buffer[1024];
	int		len;

	va_start(args, format);
	len = vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);
	if (len > 0)
		write(fd, buffer, len);
}

void	exec_cmd(char *cmd, char **envp, int fd_in, int fd_out)
{
	char	**cmd_args;
	char	*path;

	if (!cmd || !*cmd)
		(ft_printf_fd(2, "Error: Empty command\n"),
			clean_resources(NULL, fd_in, fd_out), exit(1));
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		(ft_printf_fd(2, "Error: Memory allocation failed\n"),
			clean_resources(NULL, fd_in, fd_out), exit(1));
	if (!cmd_args[0])
		(ft_printf_fd(2, "Error: Invalid command\n"),
			ft_free_split(cmd_args),
			clean_resources(NULL, fd_in, fd_out), exit(1));
	path = ft_get_cmd_path(cmd_args[0], envp);
	if (!path)
	{
		ft_printf_fd(2, "Error: %s: command not found\n", cmd_args[0]);
		ft_free_split(cmd_args);
		clean_resources(NULL, fd_in, fd_out);
		exit(127);
	}
	if (execve(path, cmd_args, envp) == -1)
		(perror("execve"), ft_free_split(cmd_args),
			free(path), clean_resources(NULL, fd_in, fd_out), exit(1));
}
