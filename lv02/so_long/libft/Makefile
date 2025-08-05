# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 10:06:26 by takawagu          #+#    #+#              #
#    Updated: 2025/07/16 16:32:18 by takawagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
NAME    = libft.a
INCDIR  = -Iincludes


SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/ft_utoa.c \
	ft_printf/print_char.c \
	ft_printf/print_str.c \
	ft_printf/print_int.c \
	ft_printf/print_unsigned.c \
	ft_printf/print_hex.c \
	ft_printf/print_pointer.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

BONUS_SRCS = \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ALL_OBJS = $(OBJS)


all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) $(NAME) $(ALL_OBJS)

bonus:
	@echo "Adding bonus files..."
	$(MAKE) ALL_OBJS="$(OBJS) $(BONUS_OBJS)" all

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	@if ls *.o >/dev/null 2>&1; then \
		echo "Cleaning object files..."; \
		rm -f $(OBJS) $(BONUS_OBJS); \
	else \
		echo "No object files to remove."; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "Removing $(NAME)..."; \
		rm -f $(NAME); \
	else \
		echo "$(NAME) not found. Nothing to remove."; \
	fi


re: fclean all

.PHONY: all clean fclean re bonus





