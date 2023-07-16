NAME	= so_long

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

INCLUDE =

SRCS    =  srcs/

LIBFT = libft/

SRC = $(srcs)main.c $(srcs)map.c $(srcs)so_long.c $(srcs)init.c \

MLX 	=   MLX42/build/libmlx42.a

MLX_H 	=	MLX42/include/MLX42/MLX42.h\

OBJ		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
