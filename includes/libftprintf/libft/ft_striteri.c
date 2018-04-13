/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:23:51 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 15:23:53 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	unsigned int		index;
	char				*a;

	index = 0;
	if (!s || f == NULL)
		return ;
	while (s[index] != '\0')
	{
		a = (char*)&s[index];
		f(index, a);
		index++;
	}
}
