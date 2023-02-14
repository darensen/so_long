SRCS = 	src/so_long.c \
		src/content.c \
		src/creat_window.c \
		src/free_destroy.c \
		src/get_map.c \
		src/get_pos.c \
		src/good_path.c \
		src/handle_event.c \
		src/map_check.c \
		src/moves.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		printf/ft_printf.c \
		printf/ft_choix.c \
		printf/ft_putchar.c \
		printf/ft_putstr.c \
		printf/ft_putnbr.c \
		printf/ft_putuint.c \
		printf/ft_puthex.c \
		printf/ft_puthexm.c \
		printf/ft_putp.c \

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

RM = rm -rf

LIB = ./minilibx/minilibx-linux/libmlx_Linux.a -g3 -lXext -lX11 -I ./minilibx/ 

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)
	clear

re: fclean all

.PHONY: all clean fclean re