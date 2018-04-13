/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:47:42 by csimon            #+#    #+#             */
/*   Updated: 2017/10/25 13:47:43 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_rooms(t_room **begin)
{
	t_room	*tmp;
	t_room	*buf;

	tmp = *begin;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp->name != NULL)
				free(tmp->name);
			if (tmp->links != NULL)
				free(tmp->links);
			buf = tmp;
			tmp = tmp->next;
			free(buf);
		}
	}
	*begin = NULL;
}

t_room	*destroy_unlinked(t_room **begin)
{
	t_room	*tmp;
	t_room	*buf;
	t_room	*prev;

	tmp = *begin;
	prev = *begin;
	while (tmp != NULL)
	{
		if (tmp != NULL && tmp->nb_links == 0 && tmp != *begin)
		{
			while (prev->next != tmp)
				prev = prev->next;
			buf = tmp;
			tmp = tmp->next;
			if (buf->name != NULL)
				free(buf->name);
			if (buf->name != NULL)
				free(buf->links);
			free(buf);
			prev->next = tmp;
		}
		else
			tmp = tmp->next;
	}
	return (*begin);
}

int		main(int argc, char const **argv)
{
	t_room	*begin;
	int		fd;
	t_path	*path;

	path = NULL;
	fd = 0;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	begin = NULL;
	begin = acquire_anthill(fd, begin);
	if (begin == NULL)
		return (0);
	begin = destroy_unlinked(&begin);
	path = find_path(begin);
	if (path != NULL)
		print_path(begin, path);
	else
		ft_printf("\nNo solution\n");
	if (begin != NULL)
		free_rooms(&begin);
	return (0);
}
