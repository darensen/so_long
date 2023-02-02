/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:21:13 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/02 14:46:46 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int map_check_C_E_P(char **str , int size)
{
    int C;
    int E;
    int P;
    int i;
    int y;

    y = 0;
    C = 0;
    E = 0;
    P = 0;
    while (str[y])
    {
        i = 0;
        while (str[y][i])
        {
            if (str[y][i] == 'C')
                C++;
            if (str[y][i] == 'E')
                E++;
            if (str[y][i] == 'P')
            {
                P++;
                if (good_path(str, y, i, size) == 0)
                    return (0);
            }
            i++;
        }
        y++;
    }
    if (C == 0 || E != 1 || P != 1) 
        return (0);
    return (1);
}

int map_check(char **str, int size, int len)
{
    int i;
    int y;
    
    y = 0;
    while (y != size)
    {
        i = 0;
        while (str[y][i])
        {
            if (str[y][i] != '0' && str[y][i] != '1' && str[y][i] != 'C' && str[y][i] != 'E' && str[y][i] != 'P' && str[y][i] != '\n')
                return (0);
            if (str[0][i] != '1' && str[0][i] != '\n' || str[size - 1][i] != '1' && str[0][i] != '\n')
                return (0);
            if (str[y][0] != '1' || str[y][len - 1] != '1')
                return (0);
            i++;
        }
        y++;
    }
    if (map_check_C_E_P(str, size) == 0)
        return (0);
    return (1);
}
