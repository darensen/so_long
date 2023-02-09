/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/09 20:31:23 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strln(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	get_size(char *str)
{
	int		fd;
	int		i;
	char	*map;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	get_map(char *str, t_data *data)
{	
	int		fd;
	int		i;
	int		y;
	char	*s;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	data->map = malloc(sizeof(char *) * (get_size(str) + 1));
	if (!data->map)
		return (0);
	s = get_next_line(fd);
	y = ft_strln(s);
	while (s)
	{
		data->map[i] = ft_strdup(s);
		if (y != ft_strln(data->map[i]))
			return (0);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	if (map_check(data->map, i, y))
		return (1);
	return (0);
}
