/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:57:33 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/13 20:00:08 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.title = av[1];
	data.move = 0;
	if (ac == 2)
	{
		if (get_map(data.title, &data) == 1)
			creat_window(&data);
		else
			ft_printf("Error\nmauvaise map");
	}
	return (0);
}
