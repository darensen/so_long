/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/13 22:14:52 by dsenatus         ###   ########.fr       */
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

int	get_ll(char *str)
{
	int		fd;
	int		i;
	char	*map;
	int		y;

	i = 0;
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (0);
	map = get_next_line(fd);
	y = ft_strln(map);
	while (map)
	{
		if (y != ft_strln(map))
			i = 2;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	if (i == 2)
		return (1);
	return (0);
}

int	get_map(char *str, t_data *data)
{	
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (0);
	data->map = malloc(sizeof(char *) * (get_size(str) + 1));
	if (!data->map)
		return (0);
	s = get_next_line(fd);
	while (s)
	{
		data->map[i] = ft_strdup(s);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	if (get_ll(str) == 0 && map_check(data->map, i, ft_strln(data->map[0])))
		return (1);
	free_map(data->map);
	return (0);
}
