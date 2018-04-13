/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_acquire3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:07:53 by csimon            #+#    #+#             */
/*   Updated: 2017/10/31 12:07:54 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*error_acquisition(t_room *begin, char **tab, int *code)
{
	*code = 666;
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
	return (begin);
}

t_room	*fill_room(t_room *begin, t_room *tmp, char **tab, int *code)
{
	if (is_larger_max_int(tab[1]) || is_larger_max_int(tab[2]))
		return (error_acquisition(begin, tab, code));
	if (begin == NULL)
		begin = create_room();
	tmp = begin;
	while (tmp->next != NULL)
	{
		if ((tmp->x_coor == ft_atoi(tab[1]) && tmp->y_coor == ft_atoi(tab[2]))
			|| !ft_strcmp(tab[0], tmp->name))
			return (error_acquisition(begin, tab, code));
		tmp = tmp->next;
	}
	if (tmp->defined == 1)
	{
		if ((tmp->x_coor == ft_atoi(tab[1]) && tmp->y_coor == ft_atoi(tab[2]))
			|| !ft_strcmp(tab[0], tmp->name))
			return (error_acquisition(begin, tab, code));
		tmp->next = create_room();
		tmp = tmp->next;
	}
	tmp->defined = 1;
	tmp->name = ft_strdup(tab[0]);
	tmp->x_coor = ft_atoi(tab[1]);
	tmp->y_coor = ft_atoi(tab[2]);
	return (begin);
}

t_room	*new_room(char *line, t_room *begin, int *code)
{
	t_room		*tmp;
	char		**tab;
	static	int tube_status = 0;

	if (*code == 666)
	{
		tube_status++;
		return (begin);
	}
	if (tube_status != 0)
	{
		*code = 666;
		return (begin);
	}
	tmp = begin;
	tab = ft_strsplit(line, ' ');
	begin = fill_room(begin, tmp, tab, code);
	if (*code != 666)
		free_tab(tab);
	return (begin);
}

void	feed_link(t_room *tmp, t_room *link, int i)
{
	if (tmp->links == NULL)
	{
		tmp->links = ft_memalloc(sizeof(t_room) * 15);
		tmp->links[0] = link;
	}
	else
	{
		while (tmp->links[i] != NULL)
			i++;
		tmp->links[i] = link;
		if (i < 9)
			tmp->links[i + 1] = NULL;
	}
}

t_room	*new_link(char *line, t_room *begin, int *code)
{
	t_room		*tmp;
	t_room		*link;
	char		**str;
	int			i;
	static	int	sp = 666;

	i = 0;
	new_room(line, begin, &sp);
	tmp = begin;
	link = begin;
	str = ft_strsplit(line, '-');
	if (!ft_strcmp(str[0], str[1]))
		return (begin);
	while (tmp != NULL && ft_strcmp(str[0], tmp->name))
		tmp = tmp->next;
	while (link != NULL && ft_strcmp(str[1], link->name))
		link = link->next;
	if (tmp == NULL || link == NULL)
		return (error_acquisition(begin, str, code));
	feed_link(tmp, link, i);
	feed_link(link, tmp, i);
	tmp->nb_links++;
	link->nb_links++;
	free_tab(str);
	return (begin);
}
