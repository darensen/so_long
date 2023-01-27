/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:08:22 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/25 17:10:50 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(char *str)
{	
 	int fd;
 	char **map;
	int i;

	i = 0;
 	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char *) * 100000);
	while(map[i] = get_next_line(fd))
	{
		printf("%s",map[i]);
		i++;
	}
	close(fd);
 	return (0);
}