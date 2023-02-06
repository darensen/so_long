/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:57:23 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/06 12:01:32 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <X11/X.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	
	char *title;
	char **map;

	int y_pos;
	int x_pos;
	
}	t_data;

int	handle_keypress(int keysym, t_data *data);
int mousepress(int mouse ,t_data *data);

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*get_str(char *get_next, int fd);
char	*line(char *get_next);
char	*next(char *str);
int	creat_window(t_data *data);
int		get_map(char *str, t_data *data);
int		map_check(char **str, int size, int len);
int	good_path(char **map, int y, int i, int size);
int	ft_strln(char *str);
char	*ft_strdup(const char *str);
void    free_map(char **str);
void	get_pos(t_data *data, char **str, int size);

#endif
