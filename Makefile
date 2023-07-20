NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

MLX42 = ./MLX42/build/libmlx42.a

SRCS = srcs/

LIBFT = libft/

SRC = $(SRCS)main1.c \
	  #$(LIBFT)ft_atoi.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_putstr.c $(LIBFT)ft_split.c $(LIBFT)ft_strlen.c $(LIBFT)ft_strcmp.c $(LIBFT)ft_strdup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re



# /Users/ihama/.brew/include/GLFW/