/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:21:23 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:21:23 by csimon           ###   ########.fr       */
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

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index];
		index++;
	}
	if (len > (ft_strlen(src)))
		while (index < len)
		{
			dst[index] = '\0';
			index++;
		}
	return (dst);
}
