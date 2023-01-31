/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/31 15:37:28 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strln(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	get_map(char *str)
{	
 	int fd;
 	char **map;
	int i;
	int y;

	i = 0;
 	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char *) * 100000);
	while(map[i] = get_next_line(fd))
	{
		if (i == 0)
			y = ft_strln(map[i]);
		if (y != ft_strln(map[i]))
		{
			return (0);
		}
		i++;
	}
	close(fd);
	if (map_check(map, i, y) == 1 )
		return (1);
 	return (0);
}
