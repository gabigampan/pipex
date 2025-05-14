/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:30:22 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/11 20:00:59 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t count)
{
	char			*dest;
	const char		*orig;
	unsigned int	n;

	dest = dst;
	orig = src;
	if (dst == 0 && src == 0)
		return (0);
	n = 0;
	while (n < count)
	{
		dest[n] = orig[n];
		n++;
	}
	return (dest);
}
