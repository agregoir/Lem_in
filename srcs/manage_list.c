/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 00:55:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/11/01 00:55:51 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room		*make_it_a_loop(t_room *begin)
{
	t_room		*current;

	current = begin;
	while (current->next)
	{
		current = current->next;
	}
	current->next = begin;
	return (current);
}

t_room		*find_the_end(t_room *begin)
{
	t_room	*current;

	current = begin;
	while (current)
	{
		if (current->type == 1)
			break ;
		current = current->next;
	}
	return (current);
}

t_room		*find_the_start(t_room *begin)
{
	t_room	*current;

	current = begin;
	while (current)
	{
		if (current->type == -1)
			break ;
		current = current->next;
	}
	return (current);
}
