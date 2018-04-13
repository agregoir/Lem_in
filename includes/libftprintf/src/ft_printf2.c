/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:41:40 by csimon            #+#    #+#             */
/*   Updated: 2017/09/14 11:41:42 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display(va_list ap, t_flags *flags, char *result, int cmx)
{
	int		len;
	int		curmax;

	curmax = cmx;
	va_end(ap);
	len = ft_strlen_zero(result, flags);
	ft_putstr_zero(result, flags);
	if (flags != NULL)
	{
		flags->backslashno = 0;
		ft_strclr(flags->length);
		free(flags->length);
		free(flags);
		flags = NULL;
	}
	call_fmt(g_tab[15], ap, flags, result);
	free(result);
	if (curmax == 1)
		return (-1);
	else
		return (len);
}

void	c_null_case(t_flags *flags)
{
	flags->cht = 1;
	flags->backslashno += 1;
	if (flags->width == -1)
		flags->width = 1;
}

char	*ft_norme2(int *backslash)
{
	*backslash = 0;
	return (NULL);
}

char	*call_fmt(t_printf g_tab, va_list ap, t_flags *flags, char *r)
{
	char		*str;
	char		*final;
	static int	backslash = 0;
	int			len;

	if (g_tab.ptr == NULL)
		return (ft_norme2(&backslash));
	len = 0;
	str = g_tab.ptr(ap, flags);
	if (str == NULL)
		return (r);
	if (str[0] == '\0' && (g_tab.flag == 'c' || g_tab.flag == 'C'))
		c_null_case(flags);
	final = ft_width_and_precision(flags, str, &len);
	if (flags->cht != 0)
	{
		flags->cht = 0;
		return (ft_strcat(r, final));
	}
	r = ft_strjoin_free_ze(r, final, 3, flags);
	len = ft_strlen_zero(r, flags);
	if (backslash > 0)
		r[len - 1] = '\0';
	return (r);
}

char	*no_conv_width(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_memalloc(size + 1);
	str[size] = '\0';
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}
