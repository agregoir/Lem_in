/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:42:35 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:42:36 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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

char			*ft_strchr(const char *s, int c)
{
	char	a;
	size_t	index;
	char	*str;

	a = c;
	index = 0;
	if (a == '\0')
		return (str = (char*)&s[ft_strlen(s)]);
	while (s[index] != '\0')
	{
		if (s[index] == a)
			return (str = (char*)&s[index]);
		index++;
	}
	return (NULL);
}
