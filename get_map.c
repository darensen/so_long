/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/02 18:14:12 by dsenatus         ###   ########.fr       */
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
int	get_map(char *str, t_data *data)
{	
 	int fd;
	int i;
	int y;
	int size;
	char *s;

	i = 0;
 	fd = open(str, O_RDONLY);
	size = get_size(str);
	data->map = malloc(sizeof(char *) * (size + 1));
	if (!data->map)
		return (0);
	while ((s = get_next_line(fd)))
	{
		data->map[i] = ft_strdup(s);
		if (i == 0)
			y = ft_strln(data->map[i]);
		if (y != ft_strln(data->map[i]))
			return (0);
		free(s);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	if (map_check(data->map, i, y) == 1 && i != y)
		return (1);
 	return (0);
}
