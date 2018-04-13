/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:31:17 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 12:31:19 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	a;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrsrc = (unsigned char*)src;
	ptrdst = (unsigned char*)dst;
	a = c;
	index = 0;
	while (index < n)
	{
		ptrdst[index] = ptrsrc[index];
		if (ptrsrc[index] == a)
			return (&ptrdst[index + 1]);
		index++;
	}
	return (NULL);
}
