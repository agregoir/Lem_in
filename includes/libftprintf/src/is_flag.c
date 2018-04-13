/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:24:54 by csimon            #+#    #+#             */
/*   Updated: 2017/09/11 14:24:55 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_space_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		is_minus_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		is_plus_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int		is_diese_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		is_zero_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
