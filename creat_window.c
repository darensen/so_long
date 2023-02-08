/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:57 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 20:36:51 by dsenatus         ###   ########.fr       */
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
	data->wall = put_img(data , "./xpm/wall.xpm");
	data->collec = put_img(data, "./xpm/collec.xpm");
	data->perso = put_img(data,"./xpm/perso.xpm");
	data->exit = put_img(data,"./xpm/exit.xpm");
	
	//mlx_xpm_to_image(data->mlx_ptr,data , int *width, int *height );
	//mlx_xpm_file_to_image(data->mlx_ptr, "xpm/grass.xpm", data->y_pos, data->x_pos);	 
	

	return (data);
}

static int	mouvement(int keysym, void *data)
{
	static int i;

	
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{	
		i = i + 1;
		printf("nombre de mouvement  %d\n", i);
	}
	return (0);
}

void   creat_window(t_data *data)
{
	data = mlx_initi(data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data); 
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &mouvement, &data);


	put_all(data, data->map, data->floor, '0');
	put_all(data, data->map, data->wall, '1');
	put_all(data, data->map, data->collec, 'C');
	put_all(data, data->map, data->perso, 'P');
	put_all(data, data->map, data->exit, 'E');

	
	mlx_loop(data->mlx_ptr);
	destroy(data);
}