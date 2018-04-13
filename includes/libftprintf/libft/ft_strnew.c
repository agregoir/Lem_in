/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:16:12 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 14:16:14 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index <= size)
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
