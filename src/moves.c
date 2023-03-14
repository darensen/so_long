/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:21:40 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/13 20:04:31 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_if_c(char **str)
{
	int	i;
	int	y;

	y = 0;
	while (str[y])
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == 'C')
				return (0);
		i++;
		}
		y++;
	}
	return (1);
}

void	move_up(t_data *data)
{
	int	a;
	int	b;

	a = data->y_pos;
	b = data->x_pos;
	if (data->map[a - 1][b] == 'E' && check_if_c(data->map) == 1)
		destroy(data);
	if (data->map[a - 1][b] != '1' && data->map[a - 1][b] != 'E')
	{
		data->map[a][b] = '0';
		a--;
		data->map[a][b] = 'P';
		data->y_pos = a;
		put_all(data, data->map, data->perso, 'P');
		put_all(data, data->map, data->floor, '0');
		data->move++;
		ft_printf("nombre de mouvemant : %d", data->move);
		write(1, "\n", 1);
	}
}

void	move_down(t_data *data)
{
	int	a;
	int	b;

	a = data->y_pos;
	b = data->x_pos;
	if (data->map[a + 1][b] == 'E' && check_if_c(data->map) == 1)
		destroy(data);
	if (data->map[a + 1][b] != '1' && data->map[a + 1][b] != 'E')
	{
		data->map[a][b] = '0';
		a++;
		data->map[a][b] = 'P';
		data->y_pos = a;
		put_all(data, data->map, data->perso, 'P');
		put_all(data, data->map, data->floor, '0');
		data->move++;
		ft_printf("nombre de mouvemant : %d", data->move);
		write(1, "\n", 1);
	}
}

void	move_left(t_data *data)
{
	int	a;
	int	b;

	a = data->y_pos;
	b = data->x_pos;
	if (data->map[a][b - 1] == 'E' && check_if_c(data->map) == 1)
		destroy(data);
	if (data->map[a][b - 1] != '1' && data->map[a][b - 1] != 'E')
	{
		data->map[a][b] = '0';
		b--;
		data->map[a][b] = 'P';
		data->x_pos = b;
		put_all(data, data->map, data->perso, 'P');
		put_all(data, data->map, data->floor, '0');
		data->move++;
		ft_printf("nombre de mouvemant : %d", data->move);
		write(1, "\n", 1);
	}
}

void	move_right(t_data *data)
{
	int	a;
	int	b;

	a = data->y_pos;
	b = data->x_pos;
	if (data->map[a][b + 1] == 'E' && check_if_c(data->map) == 1)
		destroy(data);
	if (data->map[a][b + 1] != '1' && data->map[a][b + 1] != 'E')
	{
		data->map[a][b] = '0';
		b++;
		data->map[a][b] = 'P';
		data->x_pos = b;
		put_all(data, data->map, data->perso, 'P');
		put_all(data, data->map, data->floor, '0');
		data->move++;
		ft_printf("nombre de mouvemant : %d", data->move);
		write(1, "\n", 1);
	}
}
