/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:14:35 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 12:14:37 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	size_t			index;
	char			*ptrb;

	ptrb = (char*)b;
	index = 0;
	a = c;
	while (index < len)
	{
		ptrb[index] = a;
		index++;
	}
	return (b);
}
