SRC = src/so_long.c \
		src/content.c \
		src/creat_window.c \
		src/free_destroy.c \
		src/get_map.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/get_pos.c \
		src/good_path.c \
		src/handle_event.c \
		src/map_check.c \
		src/moves.c \
		printf/ft_choix.c \
		printf/ft_printf.c \
		printf/ft_putchar.c \
		printf/ft_puthex.c \
		printf/ft_puthexm.c \
		printf/ft_putnbr.c \
		printf/ft_putp.c \
		printf/ft_putstr.c \
		printf/ft_putuint.c \

OBJS = $(SRC:.c=.o)

NAME = so_long

FLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

INC =   include

LIB = minilibx/minilibx-linux/libmlx_Linux.a -g3 -lXext -lX11 -I ./minilibx/

.c.o:
	$(CC) -I $(INC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)

	$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS) $(NAME)
	
fclean: clean
	$(RM) $(NAME)
	clear

re: fclean all

.PHONY: all clean fclean re
