/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:03:38 by agregoir          #+#    #+#             */
/*   Updated: 2017/11/01 14:42:13 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*init_t_path(t_room *room)
{
	t_path		*tmp;

	tmp = ft_memalloc(sizeof(t_path));
	tmp->name = ft_strdup(room->name);
	tmp->type = room->type;
	tmp->id_ants = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	add_end_to_path(t_room *begin, t_path *path)
{
	t_room	*end;
	t_path	*new;

	end = find_the_end(begin);
	new = init_t_path(end);
	while (path->next)
	{
		path = path->next;
	}
	path->next = new;
	new->prev = path;
}

void	add_room_to_t_path(t_room *room_to_ad, t_path *start)
{
	t_path	*new;

	if (room_to_ad->type == -1)
		return ;
	new = init_t_path(room_to_ad);
	while (start->next)
		start = start->next;
	start->next = new;
	new->prev = start;
	return ;
}

void	create_t_path(t_room *room, t_path *start, t_room *begin)
{
	int		nb_links;
	int		i;
	t_room	*tmp;
	int		tmp_weight;

	tmp = begin;
	nb_links = 0;
	while (room->type != 1)
	{
		i = 0;
		add_room_to_t_path(room, start);
		nb_links = room->nb_links;
		tmp_weight = room->links[i]->weight;
		while (nb_links-- > 0)
		{
			if (room->links[i]->weight <= tmp_weight)
			{
				tmp = room->links[i];
				tmp_weight = room->links[i]->weight;
			}
			i++;
		}
		room = tmp;
	}
	add_room_to_t_path(room, start);
}

t_path	*find_path(t_room *begin)
{
	t_room	*start_anthill;
	t_path	*start_path;

	if (begin->corrupted == 1)
		return (NULL);
	start_path = NULL;
	set_weight(begin);
	start_anthill = find_the_start(begin);
	if (start_anthill->weight <= 0)
		return (NULL);
	start_path = init_t_path(start_anthill);
	create_t_path(start_anthill, start_path, begin);
	add_end_to_path(begin, start_path);
	return (start_path);
}
