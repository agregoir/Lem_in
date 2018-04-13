/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:23:38 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 14:23:41 by csimon           ###   ########.fr       */
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

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;
	size_t		tracker;
	size_t		len2;
	char		*str;

	index = 0;
	tracker = 0;
	len2 = 0;
	if (little[index] == '\0')
		return (str = (char*)big);
	while (big[index] != '\0' && index < len)
	{
		if (big[index] == little[tracker])
		{
			len2 = index;
			while (big[len2++] == little[tracker++] && len2 <= len)
				if (tracker == ft_strlen(little))
					return (str = (char*)&big[index]);
		}
		tracker = 0;
		index++;
	}
	return (NULL);
}
