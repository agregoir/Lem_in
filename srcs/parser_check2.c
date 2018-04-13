/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:47:26 by csimon            #+#    #+#             */
/*   Updated: 2017/10/31 11:47:28 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_commentary(char *line, int len)
{
	if (len == 1 && line[0] == '#')
		return (4);
	if (len >= 2 && line[0] == '#')
	{
		if (line[1] != '#')
			return (4);
	}
	return (is_room(line, len));
}

int		is_flag(char *line, int len)
{
	if (len > 2)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			return (0);
		if (line[0] == line[1] && line[1] == '#')
			return (0);
	}
	return (is_commentary(line, len));
}

int		is_ants(char *line, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if ((line[index] < '0' || line[index] > '9'))
			return (is_flag(line, len));
		index++;
	}
	return (3);
}
