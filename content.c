/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:06:26 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 15:46:33 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    *put_img(t_data *data, char *str)
{
    int a;
    int b;

    a = 0;
    b = 0;
    return (mlx_xpm_file_to_image(data->mlx_ptr, str, &a, &b));
}

void mlx_put(t_data *data, void *path, int x, int y)
{
    //printf("%d\n", x);

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, path, 64 * x, 64 * y);
}

void put_floor(t_data *data, int x, int y, char **map)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while ( i < y )
    {
        j = 0;
        while ( j < x) 
        {
            if(map[i][j] == '0') 
            {
              //  printf("%d", i);
                mlx_put(data, data->floor, j, i);
            }
            j++;
        }
        i++;
    }
}