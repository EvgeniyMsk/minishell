# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 20:42:32 by qsymond           #+#    #+#              #
#    Updated: 2020/09/08 21:04:42 by qsymond          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CCFLAGS = -Wall -Wextra -Werror
CCFLAGS += -g
DEL = rm -rf
LIB = -L./libft -lft
LIBDIR = ./libft
FILES = ft_command.c \
		ft_environment_2.c \
		ft_input_checker_1.c \
		ft_parse_cmd_2.c \
		ft_redirect.c \
		ft_splitter.c \
		main.c \
		ft_command_2.c \
		ft_exec.c \
		ft_input_checker_2.c \
		ft_pipe_split.c \
		ft_replase.c \
		ft_terminal.c \
		ft_environment.c \
		ft_export.c \
		ft_parse_cmd.c \
		ft_quit.c \
		ft_signals.c \
		ft_utils.c

SRC = $(addprefix src/, $(FILES))
SRC += libft/get_next_line/get_next_line.c \
		libft/get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBDIR)
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "Успех!"


clean:
	@$(MAKE) clean -C $(LIBDIR)
	@$(DEL) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBDIR)
	@$(DEL) $(NAME) 1 2

leaks:
	@$(DEL) $(OBJ)
	valgrind --leak-check=full -s ./minishell

re: fclean all

.PHONY: all clean fclean sh resh re
