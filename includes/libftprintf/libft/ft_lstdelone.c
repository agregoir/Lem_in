/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:42:03 by csimon            #+#    #+#             */
/*   Updated: 2016/11/16 13:42:05 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		tmp = *alst;
		del(tmp->content, tmp->content_size);
		free(*alst);
		*alst = NULL;
	}
}
