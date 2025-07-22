# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you <you@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16                               #+#    #+#              #
#    Updated: 2024/07/16                               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MODE ?= MANDATORY

NAME = so_long

SRCS_MANDATORY = \
	main.c \
	hooks.c \
	map_utils.c \
	map_read.c \
	render.c \
	player.c \
	exit_game.c \
	check_map.c \
	check_map_utils.c

SRCS_BONUS = \
	enemy_logic_bonus.c \
	enemy_utils_bonus.c \
	main_bonus.c \
	hooks.c \
	map_utils.c \
	map_read.c \
	render.c \
	player.c \
	exit_game.c \
	check_map.c \
	check_map_utils.c

ifeq ($(MODE),BONUS)
    SRCS = $(SRCS_BONUS)
    CFLAGS += -DBONUS
else
    SRCS = $(SRCS_MANDATORY)
endif

OBJS = $(SRCS:.c=.o)
ALL_SRCS = $(SRCS_MANDATORY) $(SRCS_BONUS)
ALL_OBJS = $(ALL_SRCS:.c=.o)


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_INC = -I$(MLX_DIR)

CC = cc
CFLAGS += -Wall -Wextra -Werror $(MLX_INC) -I$(LIBFT_DIR)/includes

all: $(LIBFT) mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

bonus:
	$(MAKE) MODE=BONUS $(LIBFT) mlx $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(ALL_OBJS)

fclean: clean
	@if [ -d $(LIBFT_DIR) ]; then \
		$(MAKE) fclean -C $(LIBFT_DIR); \
	else \
		echo "$(LIBFT_DIR) not found. Skipping libft fclean."; \
	fi
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(NAME) removed."; \
	else \
		echo "$(NAME) not found. Nothing to remove."; \
	fi

re: fclean all

.PHONY: all bonus clean fclean re mlx






