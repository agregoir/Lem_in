/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:38:30 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 22:38:31 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_getnumlen(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		n++;
		n = ABS(n);
		len++;
	}
	if (n < 0)
		len++;
	n = ABS(n);
	while (n >= 10)
	{
		n /= 10;
		len += 1;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	val;
	int				i;
	char			*str;

	i = 0;
	len = ft_getnumlen(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		val = -n;
	else
		val = (unsigned int)n;
	i = 0;
	while (i < len)
	{
		str[len - 1 - i] = (val % 10) + '0';
		val /= 10;
		i++;
	}
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}
