/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:25:37 by csimon            #+#    #+#             */
/*   Updated: 2017/09/14 12:36:41 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				wchar_size(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (4);
	return (1);
}

char			*get_wchar(wchar_t c)
{
	char		*str;

	str = (char *)ft_memalloc(wchar_size(c) + 1);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = ((c >> 6) + 0xC0);
		str[1] = ((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		str[0] = ((c >> 12) + 0xE0);
		str[1] = (((c >> 6) & 0x3F) + 0x80);
		str[2] = ((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = ((c >> 18) + 0xF0);
		str[1] = (((c >> 12) & 0x3F) + 0x80);
		str[2] = (((c >> 6) & 0x3F) + 0x80);
		str[3] = ((c & 0x3F) + 0x80);
	}
	str[wchar_size(c)] = '\0';
	return (str);
}

char			*flag_upc(va_list ap, t_flags *flags)
{
	char		*str;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	str = get_wchar(c);
	if (MB_CUR_MAX < wchar_size(c))
	{
		flags->curmax = 1;
		ft_strdel(&str);
	}
	return (str);
}

char			*flag_ups_nrm(int i, wchar_t *wstr, t_flags *flags, char *str)
{
	while (wstr[i])
	{
		if (MB_CUR_MAX < wchar_size(wstr[i]))
		{
			flags->curmax = 1;
			ft_strdel(&str);
			break ;
		}
		str = ft_strjoin_free(str, get_wchar(wstr[i++]), 3);
	}
	return (str);
}

char			*flag_ups(va_list ap, t_flags *flags)
{
	wchar_t		*wstr;
	char		*str;
	int			len;
	int			i;

	str = NULL;
	flags->type = 0;
	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL)
		return (ft_strdup("(null)"));
	if ((*wstr == 0) || (*wstr == ' '))
	{
		str = (char *)ft_memalloc(1);
		return (str);
	}
	i = 0;
	len = 0;
	while (wstr[i])
		len += wchar_size(wstr[i++]);
	str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	str = flag_ups_nrm(0, wstr, flags, str);
	return (str);
}
