/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/02 16:11:26 by dsenatus         ###   ########.fr       */
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

static int get_size(char *str)
{
	int fd;
	char *map;
	int i;
	
	i = 0;
	fd = open(str, O_RDONLY);
	while((map = get_next_line(fd)))
	{
		free(map);
		i++;
	}
	close(fd);
	return (i);
}
int	get_map(char *str, char **map)
{	
 	int fd;
	int i;
	int y;
	int size;
	char *s;

	i = 0;
 	fd = open(str, O_RDONLY);
	size = get_size(str);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (0);
	while ((s = get_next_line(fd)))
	{
		map[i] = ft_strdup(s);
		if (i == 0)
			y = ft_strln(map[i]);
		if (y != ft_strln(map[i]))
			return (0);
		free(s);
		i++;
	}
	map[i] = NULL;
	close(fd);
	printf("%d%d", i, y);
	if (map_check(map, i, y) == 1 && i != y)
	{
		//free_map(map);
		return (1);
	}
 	return (0);
}
