/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:57:23 by dsenatus          #+#    #+#             */
/*   Updated: 2023/02/09 15:28:59 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
#include <X11/Xutil.h>
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
	int x_size;
	int y_size;

	void *floor;
	void *collec;
	void *wall;
	void *perso;
	void *exit;
	void *img_ptr;
	
}	t_data;

int	handle_no_event(void *data);
int	handle_keypress(int keysym, t_data *data);

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*get_str(char *get_next, int fd);
char	*line(char *get_next);
char	*next(char *str);
void	creat_window(t_data *data);
int		get_map(char *str, t_data *data);
int		map_check(char **str, int size, int len);
int	good_path(char **map, int y, int i, int size);
int	ft_strln(char *str);
char	*ft_strdup(const char *str);
void    free_map(char **str);
void	get_pos(t_data *data, char **str, char c);
void	*mlx_initi(t_data *data);
int get_size(char *str);
char	**get_mmap(char *str);
void    *put_img(t_data *data, char *str);
void mlx_put(t_data *data, void *path, int x, int y);
void put_all(t_data *data, char **map, void *aff, char c);
void    move_up(t_data *data);
void    move_left(t_data *data);
void    move_right(t_data *data);
void    move_down(t_data *data);
int    destroy(t_data *data);
#endif
