/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:21:13 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/27 20:38:49 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_check(char **str, int size)
{
    int i;
    int y;
    
    y = 0;
    i = 0;
    while (y != size)
    {
        while (str[y][i])
        {
            if (str[y][i] != '0' || str[y][i] != '1' ||str[y][i] != 'C' ||str[y][i] != 'E' |str[y][i] != 'P')
                return (0);
            i++;
        }
        y++;
    } 
    return (1);
}
