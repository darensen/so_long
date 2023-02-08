/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free&destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:18:10 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 20:36:38 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(char **str)
{
    int i;
    
    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
} 

void    destroy(t_data *data)
{
    free_map(data->map);
    mlx_destroy_image(data->mlx_ptr, data->wall);
    mlx_destroy_image(data->mlx_ptr, data->floor);
    mlx_destroy_image(data->mlx_ptr, data->exit);
    mlx_destroy_image(data->mlx_ptr, data->perso);
    mlx_destroy_image(data->mlx_ptr, data->collec);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}