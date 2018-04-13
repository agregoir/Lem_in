/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:35:52 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 15:35:53 by csimon           ###   ########.fr       */
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

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (index < len)
	{
		str[index] = f(s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
