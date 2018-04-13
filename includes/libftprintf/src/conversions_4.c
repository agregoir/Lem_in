/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:40:02 by csimon            #+#    #+#             */
/*   Updated: 2017/09/14 12:36:58 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_c(va_list ap, t_flags *flags)
{
	char		*s2;

	if (ft_strchr(flags->length, 'l'))
		return (flag_upc(ap, flags));
	s2 = (char *)ft_memalloc(sizeof(char) * 2);
	s2[0] = (char)va_arg(ap, int);
	s2[1] = '\0';
	if (s2[0] == '\0')
		flags->backslashno += 0;
	return (s2);
}

char	*flag_percent(va_list ap, t_flags *flags)
{
	char *s;

	(void)ap;
	s = (char *)ft_memalloc(sizeof(char) * 2);
	s[0] = '%';
	s[1] = '\0';
	flags->type = 5;
	return (s);
}
