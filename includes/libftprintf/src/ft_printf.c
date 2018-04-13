/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:24:35 by csimon            #+#    #+#             */
/*   Updated: 2017/09/14 12:37:50 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*no_conv_found(t_flags *f, char *r, const char *fmt, int index)
{
	if (f->width > 0 && is_minus_flag(f))
	{
		r = ft_strncat_ze(r, &fmt[index], 1, f);
		r = ft_strncat_ze(r, no_conv_width(f->width - 1), f->width, f);
	}
	else
	{
		if (f->width > 0)
			r = ft_strncat_ze(r, no_conv_width(f->width - 1), f->width, f);
		r = ft_strncat_ze(r, &fmt[index], 1, f);
	}
	return (r);
}

int		conv_found(char **result, t_flags *flags, va_list ap, int i[3])
{
	*result = call_fmt(g_tab[i[0]], ap, flags, *result);
	if (flags->curmax == 1)
	{
		*result[i[1]] = '\0';
		return (ft_display(ap, flags, *result, 1));
	}
	i[1] = ft_strlen_zero(*result, flags);
	return (0);
}

void	ft_norme(const char *format, int i[3])
{
	while (g_tab[i[0]].flag != format[i[2]] && g_tab[i[0]].flag != 0)
		(i[0])++;
}

int		start_parse(t_flags *flags, va_list ap, const char *format, int i[3])
{
	char	*result;
	int		len;

	len = 0;
	result = ft_strnew(200);
	while (format[++i[2]] != '\0')
	{
		if (format[i[2]] != '%')
			i[2] ? ft_strncat_ze(result, &format[i[2]], 1, flags)
			: ft_strncat(result, &format[i[2]], 1);
		else
		{
			i[2]++;
			flags = parse_flags(format, &i[2], flags);
			if (!format[i[2]])
				break ;
			ft_norme(format, i);
			if (g_tab[i[0]].flag == format[i[2]])
				len = conv_found(&result, flags, ap, i);
			else
				result = no_conv_found(flags, result, format, i[2]);
			i[0] = 0;
		}
	}
	return (len ? len : ft_display(ap, flags, result, 0));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i[3];
	t_flags	*flags;

	va_start(ap, format);
	i[1] = 0;
	flags = NULL;
	i[0] = 0;
	i[2] = -1;
	return (start_parse(flags, ap, format, i));
}
