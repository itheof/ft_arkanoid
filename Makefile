# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/05/02 15:46:59 by rcargou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=  check_levels.c init.c test.c ft_menu.c ft_running.c hooks.c \
			load_level.c
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
LIN_LINK	= -I$(PWD)/lib/include -I/usr/include/libdrm -L$(PWD)/lib/lib \
			  -lglfw3 -lrt -lm -lXrandr -lXinerama -lXi -lXcursor -lXrender \
			  -lGL -lm -lpthread -ldl -ldrm -lXdamage -lXfixes -lX11-xcb \
			  -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-randr \
			  -lxcb-xfixes -lxcb-render -lxcb-shape -lxcb-sync -lxshmfence \
			  -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp
LIN_INC		= -I$(PWD)/lib/include -I/usr/include/drm

all: $(NAME)

$(NAME): set_mac init_sub build_glfw build_libft $(OBJ_DIR) $(OBJ)
	@echo "Linkin'"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) $(FW)
	@echo "Done !"

linux: init_sub build_glfw build_libft $(OBJ_DIR) $(OBJ)
	@echo "Linkin'"
	@env PKG_CONFIG_PATH=$(PWD)/lib/lib/pkgconfig $(CC) \
		 $(CFLAGS) $(OBJ) $(INC) $(LIB) $(LIN_LINK)

init_sub:
	@git submodule init
	@git submodule update

set_mac:
	@LIN_INC=

build_glfw:
	@echo "Building GLFW"
	@cd lib ; cmake -DCMAKE_INSTALL_PREFIX:PATH=$(PWD)/lib \
		-BUILD_SHARED_LIBS=ON . ; make install

build_libft:
	@echo "Building Libft"
	@make -C libft

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(LIN_INC) $(CFLAGS) -c $< $(INC) -o $@

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
