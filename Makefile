# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: locharve <locharve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 05:30:41 by locharve          #+#    #+#              #
#    Updated: 2024/10/07 09:37:08 by locharve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_DIR = ./src
OBJ_DIR = ./obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

HEADERS = -I ./include -I ./libft
LIBFT = ./libft/libft.a

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRC = main.c \
	error.c \
	parsing_cub3d.c \
	t_str_utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: libft $(NAME)
	@echo "\001\e[1;32m\002Compilation OK \001\e[0m\002"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJ)
	@echo "\001\e[1;32m\002Compiling cub3d \001\e[0m\002"
	@$(CC) $(OBJ) $(LIBFT) $(HEADERS) -o $(NAME)

libft:
	@make --no-print-directory -C ./libft -s

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libft
