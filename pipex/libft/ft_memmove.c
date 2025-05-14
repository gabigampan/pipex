/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:45:27 by fragamez          #+#    #+#             */
/*   Updated: 2025/04/22 16:40:27 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	if (src == 0 && dest == 0)
		return (dest);
	if (dest > src)
		while (count--)
			*((unsigned char *)dest + count) = *((unsigned char *)src + count);
	else
		ft_memcpy(dest, src, count);
	return (dest);
}
