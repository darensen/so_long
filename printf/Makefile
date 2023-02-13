SRCS = ./ft_printf.c \
	ft_choix.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putuint.c \
	ft_puthex.c \
	ft_puthexm.c \
	ft_putp.c \

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)

HEAD = ./includes/

AR = ar rsc

RM = rm -f

NAME = libftprintf.a

.c.o:
	$(CC) $(FLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

all: $(NAME)
        
$(NAME) : $(OBJS) 
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)
		
re : fclean all

.PHONY : clean fclean all re bonus
