/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:10:10 by fragamez          #+#    #+#             */
/*   Updated: 2025/02/18 13:30:38 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			ft_error_pipex("Error creating pipe");
		}
		else
		{
			execute_program(argv, fd, env);
		}
	}
	else
	{
		ft_error_pipex("Error with the number of arguments");
	}
	return (0);
}
