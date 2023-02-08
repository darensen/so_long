/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:14 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 15:02:33 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_pos(t_data *data, char **str, char c)
{
    int x;
    int y;

    y = 0;
    while (str[y])
    {
        x = 0;
        while (str[y][x])
        { 
            if (str[y][x] == c)
            {
                data->y_pos = y;
                data->x_pos = x;
            }    
            x++;
        }
        y++;
    }
}