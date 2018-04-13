/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:48:48 by csimon            #+#    #+#             */
/*   Updated: 2017/10/25 13:48:49 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_link(char *line, int len)
{
	int		index;
	int		minus;

	index = 0;
	minus = 0;
	if (line[0] != 'L' && line[0] != '#')
		while (index < len)
		{
			if (line[index] == '-' && index > 0)
				minus++;
			if (line[index] == ' ')
				return (5);
			index++;
		}
	if (minus == 1 && line[len - 1] != '-')
		return (2);
	return (5);
}

int		is_only_digit(char *str)
{
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(str);
	while (index < len)
	{
		if ((str[index] < '0' || str[index] > '9') && str[index] != '	')
			return (0);
		index++;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		verify_room(char *line)
{
	int		i;
	char	**tab;

	i = 1;
	tab = ft_strsplit(line, ' ');
	while (tab[i] != NULL)
	{
		if ((!is_only_digit(tab[i])))
		{
			free_tab(tab);
			return (0);
		}
		if (i >= 3)
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	free_tab(tab);
	return (1);
}

int		is_room(char *line, int len)
{
	int		index;
	int		spaces;
	int		coors;

	coors = 0;
	index = 0;
	spaces = 0;
	if (line[0] != 'L' && line[0] != '#')
		while (index < len)
		{
			if (line[index] == ' ')
				spaces++;
			if (line[index] >= '0' && line[index] <= '9')
				coors++;
			if (line[index] == '-')
				return (is_link(line, len));
			index++;
		}
	if (spaces >= 2 && coors >= 2)
		if (verify_room(line) == 1)
			return (1);
	return (is_link(line, len));
}
