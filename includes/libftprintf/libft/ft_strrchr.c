/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:42:43 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:42:44 by csimon           ###   ########.fr       */
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

char			*ft_strrchr(const char *s, int c)
{
	char	a;
	int		index;
	char	*str;

	index = ft_strlen(s);
	a = c;
	if (a == '\0')
		return (str = (char*)&s[ft_strlen(s)]);
	while (index >= 0)
	{
		if (s[index] == a)
			return (str = (char*)&s[index]);
		index--;
	}
	return (NULL);
}
