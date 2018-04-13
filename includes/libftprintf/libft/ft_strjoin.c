/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:34:25 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:34:26 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

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

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	index;
	size_t			len;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		str[index] = s2[len];
		len++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
