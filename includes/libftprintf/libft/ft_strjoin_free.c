/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:07:28 by csimon            #+#    #+#             */
/*   Updated: 2017/09/04 10:07:36 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int which_one)
{
	char	*str;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	str = (char *)ft_memalloc(sizeof(*str) * (a + b + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (which_one == 1 || which_one == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (which_one == 2 || which_one == 3)
	{
		free(s2);
		s2 = NULL;
	}
	return (str);
}
