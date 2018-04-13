/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:57:16 by csimon            #+#    #+#             */
/*   Updated: 2016/11/16 13:57:18 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			del(tmp->content, tmp->content_size);
			buf = tmp;
			tmp = tmp->next;
			free(buf);
		}
	}
	*alst = NULL;
}
