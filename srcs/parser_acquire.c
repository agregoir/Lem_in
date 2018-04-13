/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:48:32 by csimon            #+#    #+#             */
/*   Updated: 2017/11/01 17:56:33 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_anthill_integrity(t_room *begin)
{
	t_room	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = begin;
	while (tmp != NULL)
	{
		if (tmp->type == -1)
			(tmp->nb_links == 0) ? start-- : start++;
		if (tmp->type == 1)
			(tmp->nb_links == 0) ? end-- : end++;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

t_room	*error_parser(t_room *begin, char *line, char *anthill, int code)
{
	if (code != -4)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (code != -4)
	{
		if (begin != NULL && code == 666)
		{
			begin->code = code;
			begin->corrupted = 1;
		}
	}
	if (anthill != NULL && code != -4)
	{
		if (code != -4 && code != -1)
		{
			ft_printf("%s", anthill);
			anthill = NULL;
		}
	}
	else if (line == NULL && code == -4)
		free(anthill);
	return (begin);
}

int		get_ants(int *ants, char *line)
{
	if (!(*ants))
	{
		if (is_larger_max_int(line) || ft_atoi(line) < 0)
			return (1);
		*ants = ft_atoi(line);
	}
	else
		return (1);
	return (0);
}

t_room	*read_anthill(int fd, t_room *begin, int *ants, char **anth)
{
	int		ret;
	int		code;
	char	*line;

	line = NULL;
	code = -4;
	ret = 1;
	while (ret >= 1)
	{
		ret = get_next_line(fd, &line);
		if (ret <= 0 || !ft_strcmp(line, ""))
			return (error_parser(begin, line, *anth, -4));
		code = is_line_valid(line);
		if (code == 3 && get_ants(ants, line))
			return (error_parser(begin, line, *anth, code));
		else if (code < 3 && (*ants))
			begin = g_fct_tab[code].ptr(line, begin, &code);
		if (code == 666 || code == 5 || (code < 3 && !(*ants)))
			return (error_parser(begin, line, *anth, 3));
		if (ret > 0)
			*anth = ft_strjoin_free(ft_strjoin_free(*anth, line, 3), "\n", 1);
	}
	if (line != NULL)
		free(line);
	return (begin);
}

t_room	*acquire_anthill(int fd, t_room *begin)
{
	int		ants;
	char	*line;
	char	*anthill;

	ants = 0;
	line = NULL;
	anthill = ft_memalloc(sizeof(char) * 2);
	begin = read_anthill(fd, begin, &ants, &anthill);
	if (begin == NULL || begin->code == 666
		|| !ants)
		return (error_parser(begin, line, anthill, -1));
	if (!check_anthill_integrity(begin))
		return (error_parser(begin, line, anthill, -2));
	if (begin != NULL)
		begin->nb_ants = ants;
	ft_printf("%s", anthill);
	if (anthill != NULL)
		free(anthill);
	return (begin);
}
