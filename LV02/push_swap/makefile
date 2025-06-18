# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 14:50:05 by takawagu          #+#    #+#              #
#    Updated: 2025/06/18 15:26:15 by takawagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# SRC = push_swap.c operations.c ...
# OBJ = $(SRC:.c=.o)

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# FT_PRINTF_DIR = ft_printf
# FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a  # 任意（printfをライブラリ化する場合）

# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# $(FT_PRINTF):      # ft_printfをライブラリ化する場合
# 	make -C $(FT_PRINTF_DIR)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

# clean:
# 	make -C $(LIBFT_DIR) clean
# 	make -C $(FT_PRINTF_DIR) clean
# 	rm -f $(OBJ)

# fclean: clean
# 	make -C $(LIBFT_DIR) fclean
# 	make -C $(FT_PRINTF_DIR) fclean
# 	rm -f $(NAME)

# re: fclean all


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = test_swap

SRC = test_main.c ops_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

