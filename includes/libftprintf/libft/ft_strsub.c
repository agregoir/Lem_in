/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:27:56 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:27:58 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	while (index < (len))
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[len] = '\0';
	return (str);
}
