# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 10:06:26 by takawagu          #+#    #+#              #
#    Updated: 2025/05/24 14:54:37 by takawagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

NAME = libftprintf.a

SRCS = \
	ft_printf.c \
	ft_printf_utils.c\
	ft_utoa.c \
	print_char.c \
	print_str.c \
	print_int.c \
	print_unsigned.c \
	print_hex.c \
	print_pointer.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) .
	ar x libft.a
	ar rcs $(NAME) $(OBJS) $(filter-out $(OBJS), *.o)
	rm -f libft.a

clean:
	rm -f $(OBJS)
	rm -f $(filter-out $(OBJS), *.o)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) libft.a
	rm -f $(filter-out $(OBJS), *.o)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re