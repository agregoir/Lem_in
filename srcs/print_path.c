/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:48:45 by agregoir          #+#    #+#             */
/*   Updated: 2017/11/01 13:49:29 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_the_fuckink_ants(t_path *path)
{
	while (path->next)
		path = path->next;
	while (path->prev)
	{
		path->id_ants = path->prev->id_ants;
		path = path->prev;
	}
	path->id_ants = 0;
	return ;
}

void	set_color(int color)
{
	if (color == -1)
		ft_putstr("\033[0m");
	if (color == 0)
		ft_putstr("\033[31m");
	if (color == 1)
		ft_putstr("\033[32m");
	if (color == 2)
		ft_putstr("\033[33m");
	if (color == 3)
		ft_putstr("\033[34m");
	if (color == 4)
		ft_putstr("\033[35m");
	if (color == 5)
		ft_putstr("\033[36m");
	if (color == 6)
		ft_putstr("\033[37m");
}

void	display(int id_ants, char *name)
{
	set_color(id_ants % 7);
	ft_putstr("L");
	ft_putnbr(id_ants);
	ft_putstr("-");
	ft_putstr(name);
	ft_putstr(" ");
	set_color(-1);
}

void	print_path2(t_path *tmp, t_path *path)
{
	while (tmp->type == 1)
	{
		move_the_fuckink_ants(path);
		tmp = path;
		while (tmp->next)
		{
			(tmp->id_ants == 0) ? 0 : display(tmp->id_ants, tmp->name);
			tmp = tmp->next;
		}
		(tmp->id_ants == 0) ? 0 : ft_putendl("");
		if (tmp->id_ants == 0)
			break ;
	}
	tmp = path;
	while (tmp != NULL)
	{
		free(tmp->name);
		tmp = tmp->next;
		free(path);
		path = tmp;
	}
}

void	print_path(t_room *room, t_path *path)
{
	int		nb_ants;
	int		i;
	t_path	*tmp;

	i = 0;
	ft_putendl("");
	room = find_the_start(room);
	nb_ants = room->nb_ants;
	while (nb_ants)
	{
		i++;
		move_the_fuckink_ants(path);
		path->id_ants = i;
		tmp = path;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, room->name))
				(tmp->id_ants == 0) ? 0 : display(tmp->id_ants, tmp->name);
			tmp = tmp->next;
		}
		ft_putendl("");
		nb_ants--;
	}
	print_path2(tmp, path);
}
