/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:49:19 by csimon            #+#    #+#             */
/*   Updated: 2017/10/25 13:49:20 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libftprintf/src/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_path
{
	char			*name;
	int				type;
	int				id_ants;
	struct s_path	*next;
	struct s_path	*prev;
}				t_path;

typedef	struct	s_room
{
	char			*name;
	int				type;
	int				weight;
	int				visited;
	int				nb_links;
	int				defined;
	int				nb_ants;
	int				x_coor;
	int				y_coor;
	int				code;
	int				corrupted;
	struct s_room	*next;
	struct s_room	**links;
}				t_room;

typedef	struct	s_parse
{
	t_room*	(*ptr)(char *line, t_room *begin, int *code);
}				t_parse;

int				is_ants(char *line, int len);
t_room			*acquire_anthill(int fd, t_room *begin);
t_room			*create_room(void);
t_room			*check_flag(char *line, t_room *begin, int *code);
t_room			*new_room(char *line, t_room *begin, int *code);
t_room			*new_link(char *line, t_room *begin, int *code);
int				is_room(char *line, int len);
int				is_line_valid(char *line);
t_room			*create_room(void);
t_room			*check_flag(char *line, t_room *begin, int *code);
int				is_larger_max_int(char *str);
t_room			*error_acquisition(t_room *begin, char **tab, int *code);
t_room			*new_room(char *line, t_room *begin, int *code);
t_room			*new_link(char *line, t_room *begin, int *code);
void			free_tab(char **tab);
t_room			*destroy_unlinked(t_room **begin);

t_path			*init_t_path(t_room *room);
void			add_end_to_path(t_room *begin, t_path *path);
void			add_room_to_t_path(t_room *room_to_ad, t_path *start);
void			create_t_path(t_room *room, t_path *start, t_room *begin);
t_path			*find_path(t_room *begin);

void			move_the_fuckink_ants(t_path *path);
void			set_color(int color);
void			display(int id_ants, char *name);
void			print_path(t_room *room, t_path *path);

void			add_weight_to_aux_room(t_room *current);
int				get_the_len(t_room *room);
int				search_a_room_to_go(t_room **room, int weight);
int				weight_is_set(t_room *room);
void			set_weight(t_room *begin);

t_room			*make_it_a_loop(t_room *begin);
t_room			*find_the_end(t_room *begin);
t_room			*find_the_start(t_room *begin);

static t_parse g_fct_tab[3] =
{
	{&check_flag},
	{&new_room},
	{&new_link},
};

#endif
