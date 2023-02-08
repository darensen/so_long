/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:19:19 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/08 20:09:43 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	int		taille;

	taille = 0;
	i = 0;
	while (s[taille])
		taille++;
	dest = malloc(sizeof(char) * (taille + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char    **newmap(char **map, int size)
{
    int i;
    char **map1;
    
    i = 0;
    map1 = malloc(sizeof(char *) *  (size + 1));
    if (!map1)
        return (NULL);
    while(map[i] != NULL)
    {
        map1[i] = ft_strdup(map[i]);
        i++;
    }
    map1[i] = NULL;
    return (map1);
}

static void flood_fill(char **map1 , int y, int i)
{
    if (map1[y][i] == '1' || map1[y][i] == 'X' || map1[y][i] == 'F')
            return ;
    if (map1[y][i] == 'E')
    {
        map1[y][i] = 'F';
        return ;
    }
    else
    {
        map1[y][i] = 'X';
        flood_fill(map1, y + 1, i);
        flood_fill(map1, y - 1, i);
        flood_fill(map1, y, i + 1);
        flood_fill(map1, y, i - 1);
    }
}

static int check_all(char **str, int size, int len)
{
    int i;
    int y;

    y = 0;
    while (y !=  size)
    {
        i = 0;
        while (i != len)
        {
            if (str[y][i] == 'C' || str[y][i] == 'E')
            {    
                return (0);
            }
            i++;
        }
        y++;
    }
    return (1);
}
int good_path(char **map, int y, int i, int size)
{
    char **map1;
    int o;
    int len;

    o = 0;
    if (o == 0)
    {
        map1 = newmap(map ,size);
        o++;
    }
    flood_fill(map1, y, i);
    len = ft_strln(map1[1]);
    if (check_all(map1, size, len) == 1)
    {
        free_map(map1);
        return (1);
    }
    free_map(map1);
    return (0);
}