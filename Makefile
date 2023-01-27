SRCS = ./

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)

HEAD = ./mlx_linux

AR = ar rsc

RM = rm -f

NAME = so_long.a

.c.o:
	$(CC) $(FLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

all: $(NAME)
        
$(NAME) : $(OBJS) 
	$(AR) $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
