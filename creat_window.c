/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:57 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/25 15:52:52 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int mousepress(int mouse ,t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return(0);
}

void    creat_window(t_data data)
{    
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "so_long");
	
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, keypress, &data);
	mlx_mouse_hook(data.win_ptr, mousepress, &data);
	mlx_loop(data.mlx_ptr);
}