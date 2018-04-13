/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:49:03 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 13:49:04 by csimon           ###   ########.fr       */
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

char			*ft_strstr(const char *big, const char *little)
{
	size_t		index;
	size_t		tracker;
	size_t		len;
	char		*str;

	index = 0;
	tracker = 0;
	len = 0;
	if (little[index] == '\0')
		return (str = (char*)big);
	while (big[index] != '\0')
	{
		if (big[index] == little[tracker])
		{
			len = index;
			while (big[len++] == little[tracker++])
				if (tracker == ft_strlen(little))
					return (str = (char*)&big[index]);
		}
		tracker = 0;
		index++;
	}
	return (NULL);
}
