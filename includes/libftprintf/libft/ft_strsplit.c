/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:55:36 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:55:38 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		ft_wrdcnt(char const *s, char c)
{
	int		counter;
	int		index;

	index = 0;
	counter = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index] != '\0')
			counter++;
		while (s[index] != c && s[index] != '\0')
			index++;
	}
	return (counter);
}

static int		ft_wdl(char const *s, char c, int index)
{
	int		wordlen;

	wordlen = 0;
	while (s[index] == c)
		index += 1;
	while (s[index] != c && s[index] != '\0')
	{
		index += 1;
		wordlen++;
	}
	return (wordlen);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wd;
	int		index;
	int		index2;

	index2 = 0;
	index = 0;
	wd = 0;
	if (!s)
		return (tab = (char**)&s);
	tab = (char**)ft_memalloc(sizeof(char*) * (ft_wrdcnt(s, c) + 2));
	while (s[index] != '\0' && wd < ft_wrdcnt(s, c))
	{
		while (s[index] == c)
			index++;
		tab[wd] = (char*)ft_memalloc(sizeof(char) * (ft_wdl(s, c, index) + 1));
		while (s[index] != c && s[index] != '\0')
			tab[wd][index2++] = s[index++];
		tab[wd++][index2] = '\0';
		index2 = 0;
	}
	tab[wd] = NULL;
	return (tab);
}
