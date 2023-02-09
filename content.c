/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:26 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/09 20:00:09 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(t_data *data, char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	return (mlx_xpm_file_to_image(data->mlx_ptr, str, &a, &b));
}

void	mlx_put(t_data *data, void *path, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, path, 64 * x, 64 * y);
}

void	put_all(t_data *data, char **map, void *aff, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				mlx_put(data, aff, j, i);
			}
			j++;
		}
		i++;
	}
}
