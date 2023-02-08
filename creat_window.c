/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:57 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 15:51:40 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *mlx_initi(t_data *data)
{
	data->mlx_ptr = mlx_init();


	data->y_size = get_size(data->title);
	data->x_size = ft_strln(data->map[0]);
	get_pos(data, data->map, 'P');

	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x_size  *64 , data->y_size *64 , "so_long");

	data->floor = put_img(data,"./xpm/grass.xpm");
	printf("%p", data->floor);
	//mlx_xpm_to_image(data->mlx_ptr,data , int *width, int *height );
	//mlx_xpm_file_to_image(data->mlx_ptr, "xpm/grass.xpm", data->y_pos, data->x_pos);	 
	

	return (data);
}

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void   creat_window(t_data *data)
{
	data = mlx_initi(data);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_size, data->y_size);
    if (!data->img_ptr)
        return ;
	
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data->win_ptr, handle_keypress, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data); 

	put_floor(data, data->x_size, data->y_size, data->map);

	
	mlx_loop(data->mlx_ptr);
	
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);

}