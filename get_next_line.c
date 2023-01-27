/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:04:59 by dsenatus          #+#    #+#             */
/*   Updated: 2023/01/25 15:48:47 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_str(char *get_next, int fd)
{
	int		i;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(get_next, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		get_next = ft_strjoin(get_next, buffer);
		if (i == 0 && get_next)
		{
			free(buffer);
			return (get_next);
		}
	}
	free(buffer);
	return (get_next);
}

char	*line(char *get_next)
{
	int		i;
	char	*line;

	i = 0;
	if (!get_next[i])
		return (NULL);
	while (get_next[i] && get_next[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (get_next[i] && get_next[i] != '\n')
	{
		line[i] = get_next[i];
		i++;
	}
	if (get_next[i] == '\n')
	{
		line[i] = get_next[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next(char *get_next)
{
	int		i;
	int		y;
	char	*line;

	i = 0;
	y = 0;
	while (get_next[i] && get_next[i] != '\n')
		i++;
	if (!get_next[i])
	{
		free(get_next);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(get_next) - i) + 1);
	if (!line)
		return (NULL);
	i++;
	while (get_next[i])
	{
		line[y++] = get_next[i++];
	}
	line[y] = '\0';
	free(get_next);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*get_line;
	static char	*get_next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	get_next = get_str(get_next, fd);
	if (!get_next)
		return (NULL);
	get_line = line(get_next);
	get_next = next(get_next);
	return (get_line);
}

/*
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdio.h>

 int	main()
 {
 	int fd;
 	char *str = NULL;

 	fd = open("dad.txt", O_RDONLY);
 	while ((str = get_next_line(fd)))
 	{
 	 	printf("%s", str); 	
	 	free(str);
	}
 	close(fd);
 	return (0);
}*/