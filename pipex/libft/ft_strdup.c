/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:53:04 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/13 15:45:13 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	int		size;

	size = ft_strlen(s);
	p = malloc(sizeof(char) * (size + 1));
	if (p == 0)
		return (0);
	ft_memcpy(p, s, size);
	p[size] = '\0';
	return (p);
}
