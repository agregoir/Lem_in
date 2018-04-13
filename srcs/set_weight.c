/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 00:56:46 by agregoir          #+#    #+#             */
/*   Updated: 2017/11/01 14:00:03 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		add_weight_to_aux_room(t_room *current)
{
	int		i;

	i = 0;
	if (current->visited == 1)
		return ;
	while (i < current->nb_links)
	{
		if (((current->links[i]->weight == 0) ||
			((current->links[i]->weight == -1) &&
			(current->links[i]->type == -1))) &&
			(current->links[i]->visited == 0))
		{
			current->links[i]->weight = (current->weight) + 1;
			if (current->type == 1)
				current->links[i]->weight += 1;
		}
		i++;
	}
	current->visited = 1;
}

int			get_the_len(t_room *room)
{
	t_room		*tmp;
	int			len;

	len = 0;
	tmp = room;
	while (room)
	{
		len++;
		room = room->next;
		if (room == tmp)
			break ;
	}
	return (len);
}

int			search_a_room_to_go(t_room **room, int weight)
{
	int		len_list;
	int		index;

	index = 0;
	len_list = get_the_len((*room));
	while (index < len_list)
	{
		if (((*room)->next->visited == 0)
			&& ((*room)->next->weight == weight))
		{
			(*room) = (*room)->next;
			return (1);
		}
		(*room) = (*room)->next;
		index++;
	}
	return (0);
}

int			weight_is_set(t_room *room)
{
	int		len_list;
	int		index;

	index = 0;
	len_list = get_the_len(room);
	while (index < len_list)
	{
		if (room->weight != 0)
			index++;
		else
			break ;
		room = room->next;
	}
	if (index == len_list)
		return (1);
	return (0);
}

void		set_weight(t_room *begin)
{
	t_room		*current;
	t_room		*start;
	t_room		*tmp;
	int			weight;

	tmp = make_it_a_loop(begin);
	start = find_the_start(begin);
	current = find_the_end(begin);
	weight = 0;
	current->weight = -1;
	while (!(weight_is_set(begin)))
	{
		if (current->type == 1)
		{
			add_weight_to_aux_room(current);
			weight++;
		}
		if (search_a_room_to_go(&current, weight))
			add_weight_to_aux_room(current);
		else
			weight++;
		if (weight == 500)
			break ;
	}
	tmp->next = NULL;
}
