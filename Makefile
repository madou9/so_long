NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/

LIBFT = ./libft/libft.a

INCLUDE = -I./include
SRC = $(SRCS)so_long.c $(SRCS)map.c $(SRCS)init_game.c  $(SRCS)check_map.c  $(SRCS)check_map1.c  $(SRCS)player_check.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./Libft
	rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

# PROJECT = so long
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
# NAME = so_long
# LIBFT = ./libft/libft.a
# MLX42 = ./MLX42/libmlx42.a
# INCLUDE = -I./include
# SRC =  ./src/so_long.c ./src/render_map.c		\
# OBJ_DIR = obj

# all: $(NAME)

# $(NAME): $(LIBFT) $(MLX42) $(OBJ)	
# 	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(MLX42FLAGS)
# 	@echo "$(CYAN)-------------------------------------------"
# 	@echo "	$(NAME) = NOW READY FOR USE!"
# 	@echo "-------------------------------------------$(RESET)"

# $(LIBFT):
# 	@$(MAKE) -C ./Libft

# $(MLX42):
# 	@$(MAKE) -C ./MLX42

# $(OBJ_DIR)/%.o: ./src/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Compiled ✅ $(CYAN) $^ $(RESET)"
# 	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

# clean:
# 	@$(MAKE) clean -C ./Libft
# 	@$(MAKE) clean -C ./MLX42
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@$(MAKE) fclean -C ./Libft
# 	@$(MAKE) fclean -C ./MLX42
# 	@rm -f $(NAME)
# 	@echo "$(GREEN) $(PROJECT) $(RESET) Cleansed ✅"

# re: fclean all

# .PHONY: all clean fclean re
