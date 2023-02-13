/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:57:33 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/13 22:07:55 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char *str)
{
	int	i;

	i = ft_strln(str);
	i--;
	if (str[i] != 'r')
		return (0);
	i--;
	if (str[i] != 'e')
		return (0);
	i--;
	if (str[i] != 'b')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.title = av[1];
	if (check_ber(data.title) == 0)
	{
		ft_printf("Error\nmauvaise extansion");
		return (0);
	}
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
