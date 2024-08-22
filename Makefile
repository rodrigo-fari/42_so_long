# Makefile settings
MAKEFLAGS += -s

# Project settings
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Paths
LIBFT_DIR = libft/
MLX_DIR = mlx/
MLX_PATH = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_INCLUDE = -I/usr/include -Imlx

# Source files
SRC = so_long.c map_checker.c map_validation.c flood_fill.c mem_clear.c \
	window_handler.c render.c 
OBJ = $(SRC:.c=.o)

# Libraries
LIBFT_A = $(LIBFT_DIR)libft.a

# Scripts
TEST = val.sh

# Default target
all: $(MLX_PATH) $(NAME)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Linking the final executable
$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_A) $(MLX_FLAGS)

# Building the MLX library
$(MLX_PATH):
	@$(MAKE) -C $(MLX_DIR)

# Building the libft library
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# Compiling object files
%.o: %.c
	$(CC) $(FLAGS) -c $< $(MLX_INCLUDE)

# Cleaning object files
clean:
	$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

# Full cleanup
fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Cleaned Successfully! ║"
	@echo "╚══════════════════════════╝"

# Rebuild everything
re: fclean all

# Leak testing
leak: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/invalid_map/empty_line_in_between.ber

# Run tests
test: re
	./$(TEST)