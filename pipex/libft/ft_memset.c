/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:53:56 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/12 13:56:34 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t count)
{
	unsigned char	*copy;
	size_t			n;

	copy = str;
	n = 0;
	while (n < count)
	{
		copy[n] = c;
		n++;
	}
	return (str);
}
