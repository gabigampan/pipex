/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:34:09 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/13 13:36:35 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	h;
	size_t	i;

	h = 0;
	if (s2[h] == '\0')
		return ((char *)s1);
	while (s1[h])
	{
		i = 0;
		while (s1[h + i] == s2[i] && (h + i) < n)
		{
			if (s1[h + i] == '\0' && s2[i] == '\0')
				return ((char *)s1 + h);
			else
				i++;
		}
		if (s2[i] == '\0')
			return ((char *)s1 + h);
		else
			h++;
	}
	return (0);
}
