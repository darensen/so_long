/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:21:13 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/09 19:38:22 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_e(char **str)
{
	int	e;
	int	i;
	int	y;

	y = 0;
	e = 0;
	while (str[y])
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == 'E')
				e++;
			i++;
		}
		y++;
	}
	if (e != 1)
		return (0);
	return (1);
}

static int	check_c(char **str)
{
	int	c;
	int	i;
	int	y;

	y = 0;
	c = 0;
	while (str[y])
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == 'C')
				c++;
			i++;
		}
		y++;
	}
	if (c == 0)
		return (0);
	return (1);
}

static int	check_p(char **str, int size)
{
	int	p;
	int	i;
	int	y;

	y = 0;
	p = 0;
	while (str[y])
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == 'P')
			{
				p++;
				if (good_path(str, y, i, size) == 0)
					return (0);
			}
			i++;
		}
		y++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	map_check(char **str, int size, int len)
{
	int	i;
	int	y;

	y = 0;
	while (str[y])
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] != '0' && str[y][i] != '1'
					&& str[y][i] != 'C' && str[y][i] != 'E'
					&& str[y][i] != 'P' && str[y][i] != '\n')
				return (0);
			if (str[0][i] != '1' && str[0][i] != '\n'
					|| str[size - 1][i] != '1' && str[0][i] != '\n')
				return (0);
			if (str[y][0] != '1' || str[y][len - 1] != '1')
				return (0);
			i++;
		}
		y++;
	}
	if ((check_p(str, size) == 0) || (check_e(str) == 0) || (check_c(str) == 0))
		return (0);
	return (1);
}
