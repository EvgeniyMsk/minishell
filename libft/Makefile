# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 20:42:05 by qsymond           #+#    #+#              #
#    Updated: 2020/09/08 20:42:06 by qsymond          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = ./includes/ft_printf.h
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = printf/ft_output.c \
		printf/ft_printf.c \
		printf/ft_spreader.c \
		printf/ft_str_tolower.c \
		printf/ft_uns_itoa_base.c \
		printf/ft_view_char.c \
		printf/ft_view_flags.c \
		printf/ft_view_hex.c \
		printf/ft_view_int.c \
		printf/ft_view_percent.c \
		printf/ft_view_ptr.c \
		printf/ft_view_str.c \
		printf/ft_view_uint.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(ARRC) $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(REMF) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(REMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
