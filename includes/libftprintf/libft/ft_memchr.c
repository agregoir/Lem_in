/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:09:43 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 16:09:44 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	size_t			index;
	void			*result;
	unsigned char	*ptrs;

	ptrs = (unsigned char*)s;
	index = 0;
	a = c;
	while (index < n)
	{
		if (ptrs[index] == a)
		{
			result = &ptrs[index];
			return (result);
		}
		index++;
	}
	return (NULL);
}
