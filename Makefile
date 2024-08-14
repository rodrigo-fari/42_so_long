MAKEFLAGS += -s

# Nome do executável
NAME = so_long

# Diretórios
PATH_LIBFT = libft/
MLX_PATH = mlx/

# Bibliotecas
LIBFT_A = $(PATH_LIBFT)libft.a
MLX_LIB_MAC = $(MLX_PATH)libmlx.a
MLX_LIB_LINUX = $(MLX_PATH)libmlx_Linux.a

# Compilador e flags
CC = cc
FLAGS = -Wall -Wextra -Werror
CFLAGS_MAC = $(FLAGS) -DGL_SILENCE_DEPRECATION -Imlx
CFLAGS_LINUX = $(FLAGS) -Imlx -I/usr/include
RM = rm -rf

# Configurações do macOS
MLX_MAC = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# Configurações do Linux
MLX_LINUX = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11

# Sources e objetos
SRC = so_long.c map_checker.c map_validation.c flood_fill.c \
	mem_clear.c
OBJ = $(SRC:.c=.o)

# Detecta o sistema operacional
UNAME_S := $(shell uname -s)

# Configurações específicas por sistema operacional
ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = $(MLX_MAC)
	CFLAGS = $(CFLAGS_MAC)
else
	MLX_FLAGS = $(MLX_LINUX)
	CFLAGS = $(CFLAGS_LINUX)
	MLX_LIB = $(MLX_LIB_LINUX)
endif

# Regras de compilação
all: $(NAME)
	clear
	echo "╔══════════════════════════╗"
	echo "║ ✅ Compiled Successfully!║"
	echo "╚══════════════════════════╝"

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(MLX_FLAGS)

$(LIBFT_A):
	$(MAKE) -C $(PATH_LIBFT)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(PATH_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PATH_LIBFT)
	clear
	echo "╔══════════════════════════╗"
	echo "║ ✅ Cleaned Successfully! ║"
	echo "╚══════════════════════════╝"

re: fclean all

leak: re
	valgrind --leak-check=full --show-leak-kinds=all \
		./$(NAME) maps/invalid_map/empty_line_in_between.ber

test: re
	./$(TEST)