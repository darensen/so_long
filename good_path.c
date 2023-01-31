/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:19:19 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/31 21:06:44 by dsenatus         ###   ########.fr       */
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
    map1 = malloc(sizeof(char *) * size + 1);
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
    int l;
    l = 0;
   
    if (map1[y][i] == '1' || map1[y][i] == 'X')
            return ;
    else 
    {
        map1[y][i] = 'X';
        while (map1[l])
        {
            printf("%s", map1[l]);
            l++;
        }
        printf("\n\n");
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
    int b;
    int len;

    o = 0;
    if (o == 0)
    {
        map1 = malloc(sizeof(char *) * size);
        map1 = newmap(map ,size);
        o++;
    }
    flood_fill(map1, y, i);
    len = ft_strln(map1[1]);
    if (check_all(map1, size, len) == 1)
        return (1);
    else
        return (0);
    return (0);
}