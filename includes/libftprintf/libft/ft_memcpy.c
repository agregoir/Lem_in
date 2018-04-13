/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:25:22 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 12:25:24 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*ptrsrc;
	char	*ptrdst;

	ptrdst = (char*)dst;
	ptrsrc = (char*)src;
	index = 0;
	if (n == 0)
		return (ptrdst);
	while (index < n)
	{
		ptrdst[index] = ptrsrc[index];
		index++;
	}
	return (ptrdst);
}
