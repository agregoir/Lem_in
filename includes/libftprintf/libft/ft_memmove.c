/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:23:44 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 15:23:46 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	char		*psrc;
	size_t		i;

	pdst = (char*)dst;
	psrc = (char*)src;
	i = 0;
	if (psrc > pdst)
	{
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			pdst[len - 1 - i] = psrc[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
