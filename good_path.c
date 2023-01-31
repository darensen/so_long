/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:19:19 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/31 17:47:59 by dsenatus         ###   ########.fr       */
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

int good_path(char **map, int y, int i, int size)
{
    char **map1;
    int o;

    o = 0;
    if (o == 0)
    {
        map1 = malloc(sizeof(char *) * size);
        map1 = newmap(map ,size);
        o++;
    } 
    
    good_path(map1, y + 1, i, size);
    good_path(map1, y - 1, i, size);
    good_path(map1, y, i + 1 ,size);
    good_path(map1, y, i - 1 ,size);  
}