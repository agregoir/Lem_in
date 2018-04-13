/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:30:05 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:30:07 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	index;
	char	*str;

	str = (char*)s;
	index = 0;
	while (str[index])
		index++;
	return (index);
}

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = ft_strlen(s1);
	while (s2[counter] != '\0' && counter < n)
	{
		s1[index] = s2[counter];
		index++;
		counter++;
	}
	s1[index] = '\0';
	return (s1);
}
