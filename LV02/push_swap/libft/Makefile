# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 10:06:26 by takawagu          #+#    #+#              #
#    Updated: 2025/05/15 09:23:24 by takawagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# コンパイラとフラグの設定
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
NAME    = libft.a
INCDIR  = -I.

# ソースファイルの定義
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
	ft_putnbr_fd.c

BONUS_SRCS = \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


ifdef BONUS
ALL_OBJS = $(OBJS) $(BONUS_OBJS)
else
ALL_OBJS = $(OBJS)
endif

# デフォルトターゲット
all: $(NAME)

# ライブラリの作成
$(NAME): $(ALL_OBJS)
	$(AR) $(NAME) $(ALL_OBJS)

# bonus ターゲット
bonus:
	$(MAKE) BONUS=1


# コンパイルルール
%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

# クリーンアップ
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus


