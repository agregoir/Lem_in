/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:11:57 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 16:11:58 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char*)s1;
	ptrs2 = (unsigned char*)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (ptrs1[index] != ptrs2[index])
			return (ptrs1[index] - ptrs2[index]);
		index++;
	}
	return (0);
}
