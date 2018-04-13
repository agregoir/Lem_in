/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:00:32 by csimon            #+#    #+#             */
/*   Updated: 2017/03/07 21:08:33 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_list1
{
	int				fd;
	char			*save;
	struct s_list1	*next;
}					t_list1;

int					get_next_line(const int fd, char **line);

#endif
