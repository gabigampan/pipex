/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:51:03 by fragamez          #+#    #+#             */
/*   Updated: 2025/05/14 17:02:39 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

/*ERROR*/

void	ft_error_pipex(char *msg);

/*GET_PATH*/

char	*ft_get_cmd_path(char *argv, char **path);
char	**ft_get_paths(char **env);

/*PIPEX*/

void	process_first_child(char **argv, int *fd, char **env);
void	process_second_child(char **argv, int *fd, char **env);
void	execute_program(char **argv, int *fd, char **env);

/*UTILS*/

void	operate_dup2(int fd_old, int fd_new);
void	ft_free_split(char **split);
void	clean_resources(int *pipe_fd, int fd_in, int fd_out);
void	ft_printf_fd(int fd, const char *format, ...);
void	exec_cmd(char *cmd, char **envp, int fd_in, int fd_out);

#endif