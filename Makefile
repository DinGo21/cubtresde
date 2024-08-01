NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math -g

RM = rm -rf

SRC_DIR = src/
#BONUS_DIR = src_bonus/
LIBFT_DIR = libft/
MLX_DIR = MLX42/build/
OBJ_DIR = obj/

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
# BONUS_FILES = $(notdir $(wildcard $(BONUS_DIR)*.c))
OBJ_FILES = $(SRC_FILES:.c=.o)
# OBJ_FILES_BONUS = $(BONUS_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX = $(addprefix $(MLX_DIR), libmlx42.a)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
# OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES_BONUS))

INCLUDES = -I include/
LIBS := -ldl -lglfw -pthread -lm

all: obj $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C libft all

$(MLX):
	@cd MLX42 && cmake -B build && cd ..
	@make -C MLX42/build

obj:
	mkdir -p $(OBJ_DIR)

# bonus: obj $(NAME)
# 	$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
# 		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 	$(NAME): $(OBJ) $(LIBFT) $(MLX)
# 		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) $(LIBS) -o $(NAME)

# 	$(LIBFT):
# 		@make -C libft all

# 	$(MLX):
# 		@cd MLX42 && cmake -B build && cd ..
# 		@make -C MLX42/build

clean:
	@make -C libft clean
	@make -C MLX42/build clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
