# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/05/01 23:30:02 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= test.c
NAME	= ft_arkanoid
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls -g\
		  -Wmissing-declarations
SRC_DIR	= srcs
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes -I./lib/include/GLFW
OBJ_DIR	= objs
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Building Libft"
	@make -C Libft
	@echo "Building GLFW"
	@cd lib
	@cmake DCMAKE_INSTALL_PREFIXPATH=$PWD/glfw/lib .
	@make
	@cd ..
	@echo "Linkin'"
	@$(CC) $(CFLAGS) $(SRCS) $(INC) $(LIB)
	@echo "Done !"

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting archive library."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
