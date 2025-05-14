/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:50:58 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/13 13:50:02 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*s2;

	s2 = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		end = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[end -1] && ft_strchr(set, s1[end -1]) && end > i)
			end--;
		s2 = (char *)malloc(sizeof(char) * (end - i +1));
		if (s2)
			ft_strlcpy(s2, &s1[i], end - i + 1);
	}
	return (s2);
}
