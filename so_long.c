/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:57:33 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/09 17:46:01 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.title = av[1];
	if (ac == 2)
	{
		if (get_map(data.title, &data) == 1)
			creat_window(&data);
		else
			printf("erreur de map");
	}
	return (0);
}
