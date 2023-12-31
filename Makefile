NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/

LIBFT = ./libft/libft.a

SRC = $(SRCS)start_game.c $(SRCS)so_long.c $(SRCS)read_map.c $(SRCS)init_game.c  $(SRCS)check_map.c  $(SRCS)check_map1.c  $(SRCS)count_map.c $(SRCS)mlx_image.c $(SRCS)move.c \
	  $(SRCS)parse_map.c $(SRCS)free.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lmlx42 -L./MLX42/build -lglfw -L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -o $(NAME) 

%.o: %.c
	$(CC) -c $(CFLAGS) -g $< -o $@

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./Libft
	rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all