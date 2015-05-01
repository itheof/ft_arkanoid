# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/05/02 01:10:25 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= test.c
NAME	= ft_arkanoid
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pedantic -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls -g\
		  -Wmissing-declarations
SRC_DIR	= srcs
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes -I./lib/include/GLFW
OBJ_DIR	= objs
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
LIB		= -L./libft -lft -L./lib/lib -lglfw3
FW		= -framework Cocoa -framework OpenGL -framework IOKit -framework \
		  CoreVideo


all: $(NAME)

$(NAME): init_sub build_glfw build_libft $(OBJ_DIR) $(OBJ)
	@echo "Linkin'"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) $(FW)
	@echo "Done !"

init_sub:
	@git submodule init
	@git submodule update

build_glfw:
	@echo "Building GLFW"
	@cd lib ; cmake -DCMAKE_INSTALL_PREFIX:PATH=$(PWD)/lib \
		-BUILD_SHARED_LIBS=ON . ; make install

build_libft:
	@echo "Building Libft"
	@make -C libft

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@

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
