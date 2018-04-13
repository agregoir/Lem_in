/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:16:35 by csimon            #+#    #+#             */
/*   Updated: 2016/11/11 11:41:00 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*a;

	a = (char*)s;
	index = 0;
	while (index < n)
	{
		a[index] = 0;
		index++;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}
