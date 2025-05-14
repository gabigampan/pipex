/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:51:00 by fragamez          #+#    #+#             */
/*   Updated: 2025/02/19 17:33:57 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_first_child(char **argv, int *fd, char **env)
{
	int		infile;
	char	**path;
	char	*cmd;

	operate_dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error_pipex("Infile Error");
	operate_dup2(infile, STDIN_FILENO);
	path = ft_get_paths(env);
	if (!path)
		ft_error_pipex("Error getting **path");
	cmd = ft_get_cmd_path(argv[2], path);
	free(path);
	if (!cmd)
		ft_error_pipex("pipex: Command not found");
	if (execve (cmd, ft_split(argv[2], ' '), env) == -1)
	{
		free(cmd);
		ft_error_pipex("Execve Error");
	}
}

void	process_second_child(char **argv, int *fd, char **env)
{
	int		outfile;
	char	**path;
	char	*cmd;

	operate_dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error_pipex("Outfile error");
	operate_dup2(outfile, STDOUT_FILENO);
	path = ft_get_paths(env);
	if (!path)
		ft_error_pipex("Error getting path");
	cmd = ft_get_cmd_path(argv[3], path);
	free(path);
	if (!cmd)
		ft_error_pipex("pipex: Command not found");
	if (execve (cmd, ft_split(argv[3], ' '), env) == -1)
	{
		free(cmd);
		ft_error_pipex("Execve Error");
	}
}

void	execute_program(char **argv, int *fd, char **env)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid == -1)
		ft_error_pipex("Fork Error");
	if (pid == 0)
		process_first_child(argv, fd, env);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			ft_error_pipex("Fork Error");
		if (pid2 == 0)
		{
			process_second_child(argv, fd, env);
		}
		close(fd[0]);
		close(fd[1]);
		waitpid(pid2, NULL, WUNTRACED);
	}
}
