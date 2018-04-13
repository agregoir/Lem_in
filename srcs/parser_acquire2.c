/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_acquire2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:58:55 by csimon            #+#    #+#             */
/*   Updated: 2017/10/31 11:58:57 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_line_valid(char *line)
{
	int		len;

	len = 0;
	while (line[len] != '\0')
		len++;
	return (is_ants(line, len));
}

t_room	*create_room(void)
{
	t_room		*tmp;

	tmp = ft_memalloc(sizeof(t_room));
	tmp->name = NULL;
	tmp->type = 0;
	tmp->nb_links = 0;
	tmp->defined = 0;
	tmp->nb_ants = 0;
	tmp->x_coor = -1000;
	tmp->y_coor = -1000;
	tmp->corrupted = 0;
	tmp->visited = 0;
	tmp->weight = 0;
	tmp->code = 0;
	tmp->next = NULL;
	tmp->links = NULL;
	return (tmp);
}

void	norme_status_check(int status[2], int *code)
{
	if (status[0] > 1 || status[1] > 1)
		*code = 666;
}

t_room	*check_flag(char *line, t_room *begin, int *code)
{
	t_room		*tmp;
	static int	status[2] = {0, 0};

	if (begin == NULL)
		begin = create_room();
	tmp = begin;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->defined == 1)
	{
		tmp->next = create_room();
		tmp = tmp->next;
	}
	if (!ft_strcmp(line, "##start"))
	{
		tmp->type = -1;
		status[0] += 1;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		tmp->type = 1;
		status[1] += 1;
	}
	norme_status_check(status, code);
	return (begin);
}

int		is_larger_max_int(char *str)
{
	int			index;
	long int	number;
	int			numsign;

	numsign = 1;
	number = 0;
	index = 0;
	while (str[index] != '\0' && str[index] <= 32 && str[index] != '\200')
		index++;
	if (str[index] == '-')
	{
		numsign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	if (number > 2147483647 || number < -2147483648)
		return (1);
	return (0);
}
