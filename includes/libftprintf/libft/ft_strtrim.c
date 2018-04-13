/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:42:38 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:42:40 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#define SPACE(x) (x != ' ' && x != '\n' && x != '\t')

char	*ft_strtrim(char const *s)
{
	int		index;
	int		start;
	int		counter;
	char	*str;

	if (!s)
		return (NULL);
	index = 0;
	counter = 0;
	while (!SPACE(s[index]))
		index++;
	start = index;
	while (s[index + 1] != '\0')
		index++;
	while (!SPACE(s[index]))
		index--;
	if ((str = (char*)malloc(sizeof(char) * (index - start) + 2)) == NULL)
		return (NULL);
	while (start <= index)
		str[counter++] = s[start++];
	str[counter] = '\0';
	return (str);
}
