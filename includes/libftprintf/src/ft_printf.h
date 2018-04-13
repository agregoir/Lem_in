/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 10:44:00 by csimon            #+#    #+#             */
/*   Updated: 2017/09/13 15:12:57 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct	s_flags
{
	char		flag[10];
	int			width;
	int			precision;
	char		*length;
	int			type;
	int			backslashno;
	int			cht;
	int			curmax;
}				t_flags;

typedef struct	s_printf
{
	char	*(*ptr)(va_list params, t_flags *flags);
	char	flag;
}				t_printf;

uintmax_t		get_uintmax_t_arg(va_list ap, t_flags *flags);
intmax_t		get_intmax_t_arg(va_list ap, t_flags *flags);
char			*ft_itoa_base_uintmax_t(uintmax_t nbr, char *base);
char			*ft_itoa_base_intmax_t(intmax_t nbr, char *base, int neg);

t_flags			*check_errors_plus(t_flags *flags);
t_flags			*check_errors_minus(t_flags *flags);
t_flags			*check_errors_flags(t_flags *flags);

char			*flag_p(va_list ap, t_flags *flags);
char			*string_back(va_list ap, t_flags *flags);
char			*flag_di(va_list ap, t_flags *flags);
char			*flag_upd(va_list ap, t_flags *flags);
char			*flag_upo(va_list ap, t_flags *flags);

char			*flag_o(va_list ap, t_flags *flags);
char			*flag_u(va_list ap, t_flags *flags);
char			*flag_upu(va_list ap, t_flags *flags);
char			*flag_x(va_list ap, t_flags *flags);
char			*flag_upx(va_list ap, t_flags *flags);

int				wchar_size(wchar_t c);
char			*get_wchar(wchar_t c);
char			*flag_upc(va_list ap, t_flags *flags);
char			*flag_ups_nrm(int i, wchar_t *wstr, t_flags *flags, char *str);
char			*flag_ups(va_list ap, t_flags *flags);

char			*flag_c(va_list ap, t_flags *flags);
char			*flag_percent(va_list ap, t_flags *flags);

char			*ft_w_and_p_2(t_flags *flags, char *str, int *len, char *s2);
char			*ft_width_and_precision(t_flags *flags, char *str, int *len);
char			*ft_width_2(char *news, t_flags *flags, char *str);
char			*ft_width(t_flags *flags, char *str, int *len);

char			*plus_flag(char *str, int *len);
char			*space_flag(char *str, int *len);
char			*diese_flag(t_flags *flags, char *s2, char *str, int *len);
char			*zero_flag_2(t_flags *flags, char *news, char **str);
char			*zero_flag(t_flags *flags, char *news, char **str);

char			*call_fmt(t_printf g_tab, va_list ap, t_flags *flags, char *r);
char			*no_conv_width(int size);
char			*ft_printf_2(t_flags *f, char *r, const char *fmt, int index);
int				ft_printf(const char *format, ...);

size_t			ft_strlen_zero(const char *s, t_flags *flags);
void			ft_putstr_zero(char const *s, t_flags *flags);
char			*ft_strcat_zero(char *s1, const char *s2, t_flags *flags);
char			*ft_strncat_ze(char *s1, const char *s2, size_t n, t_flags *f);
char			*ft_strjoin_free_ze(char *s1, char *s2, int x, t_flags *flags);

int				is_space_flag(t_flags *flags);
int				is_minus_flag(t_flags *flags);
int				is_plus_flag(t_flags *flags);
int				is_diese_flag(t_flags *flags);
int				is_zero_flag(t_flags *flags);

t_flags			*initialize_flags(void);
int				ft_comparison(char c, int action);
void			get_flags(const char *str, int *i, t_flags *parse, int j);
t_flags			*parse_flags(const char *str, int *i, t_flags *flags);

char			*string_precision(int precision, char *str, int *len);
char			*number_precision(t_flags *flags, int *len, char *str, char *s);

int				ft_display(va_list ap, t_flags *flags, char *result, int cmx);
void			c_null_case(t_flags *flags);
char			*ft_norme2(int *backslash);
char			*call_fmt(t_printf g_tab, va_list ap, t_flags *flags, char *r);
char			*no_conv_width(int size);

static t_printf	g_tab[16] =
{
	{&flag_percent, '%'},
	{&flag_c, 'c'},
	{&string_back, 's'},
	{&flag_di, 'd'},
	{&flag_di, 'i'},
	{&flag_u, 'u'},
	{&flag_p, 'p'},
	{&flag_o, 'o'},
	{&flag_x, 'x'},
	{&flag_upc, 'C'},
	{&flag_ups, 'S'},
	{&flag_upd, 'D'},
	{&flag_upu, 'U'},
	{&flag_upo, 'O'},
	{&flag_upx, 'X'},
	{NULL, 00}
};

#endif
