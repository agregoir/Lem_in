/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:34:58 by csimon            #+#    #+#             */
/*   Updated: 2016/11/10 14:35:00 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		index;
	int		number;
	int		numsign;

	numsign = 1;
	number = 0;
	index = 0;
	while (str[index] != '\0' && str[index] <= 32 && str[index] != '\200')
		index++;
	if (str[index] == '-')
	{
		numsign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	return (number * numsign);
}
