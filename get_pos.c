/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:14 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/06 12:46:40 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_pos(t_data *data, char **str, int size)
{
    int x;
    int y;

    y = 0;
    while (y != size)
    {
        x = 0;
        while (str[y][x])
        { 
            if (str[y][x] == 'P')
            {
                data->y_pos = y;
                data->x_pos = x;
            }    
            x++;
        }
        y++;
    }
}