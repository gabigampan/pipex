/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:27:49 by fragamez          #+#    #+#             */
/*   Updated: 2025/05/14 16:23:00 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_pipex(char *msg)
{
	write (2, msg, ft_strlen(msg));
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}
