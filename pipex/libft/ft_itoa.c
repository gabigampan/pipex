/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:48:02 by fragamez          #+#    #+#             */
/*   Updated: 2024/12/13 15:26:13 by fragamez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count(int num)
{
	int	con;

	con = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num = num *(-1);
			con++;
		}
		while (num != 0)
		{
			num = num / 10;
			con++;
		}
	}
	else
		con = 1;
	return (con);
}

char	*ft_itoa(int n)
{
	int			lon;
	char		*s;
	long int	num;

	lon = count(n);
	num = n;
	s = malloc(sizeof(char) * (lon + 1));
	if (!s)
		return (0);
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
		s[0] = '0';
	s[lon--] = '\0';
	while (num)
	{
		s[lon] = ((num % 10) + '0');
		num /= 10;
		lon--;
	}
	return (s);
}
