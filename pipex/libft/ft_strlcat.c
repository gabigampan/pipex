/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:11:17 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/13 15:09:03 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	id;
	unsigned int	is;

	is = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (is);
	id = ft_strlen(dst);
	if (id >= size)
		return (is + size);
	else
		size -= id;
	ft_strlcpy(dst + id, src, size);
	return (id + is);
}
