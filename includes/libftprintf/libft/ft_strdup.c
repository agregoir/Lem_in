/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:13:05 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:13:07 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*s2;

	index = 0;
	while (s1[index] != '\0')
		index++;
	s2 = (char*)ft_memalloc(sizeof(char) * (index + 1));
	if (s2 == NULL)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
