/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:34:45 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:34:48 by csimon           ###   ########.fr       */
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

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*ptrdst;
	const char	*ptrsrc;
	size_t		n;
	size_t		dlen;

	n = size;
	ptrdst = dst;
	ptrsrc = src;
	while (n-- != 0 && *ptrdst != '\0')
		ptrdst++;
	dlen = ptrdst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(ptrsrc));
	while (*ptrsrc != '\0')
	{
		if (n != 1)
		{
			*ptrdst++ = *ptrsrc;
			n--;
		}
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (dlen + (ptrsrc - src));
}
