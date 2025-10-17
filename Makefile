NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./gnl -I./mlx
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Get Next Line
GNL_DIR = gnl
GNL_SRCS = $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

SRCS = srcs/main.c \
       srcs/init/init_data.c \
       srcs/init/init_game.c \
       srcs/init/init_mlx.c \
       srcs/init/init_player.c \
       srcs/init/init_textures.c \
       srcs/parsing/parse_colors.c \
       srcs/parsing/parse_line.c \
       srcs/parsing/parse_map.c \
       srcs/parsing/parse_texture.c \
       srcs/parsing/validate_map.c \
       srcs/raycasting/raycasting.c \
       srcs/raycasting/dda.c \
       srcs/raycasting/wall_calculations.c \
       srcs/rendering/render.c \
       srcs/rendering/draw_wall.c \
       srcs/rendering/texture.c \
       srcs/controls/keyboard.c \
       srcs/controls/rotation.c \
       srcs/controls/mouse.c \
       srcs/controls/hooks.c \
       srcs/utils/error.c \
       srcs/utils/utils.c \
       srcs/utils/utils_array.c \
       srcs/utils/graphics.c \
       srcs/utils/cleanup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Compile MLX
$(MLX):
	@echo "$(BLUE)Compiling MLX...$(RESET)"
	@make -C $(MLX_DIR) 2>/dev/null || true
	@echo "$(BLUE)MLX ready!$(RESET)"

# Compile libft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(BLUE)Libft compiled!$(RESET)"

# Link everything - IMPORTANT: Order matters!
$(NAME): $(MLX) $(LIBFT) $(GNL_OBJS) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) -L$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS) $(GNL_OBJS)
	@make -C $(MLX_DIR) clean 2>/dev/null || true
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re