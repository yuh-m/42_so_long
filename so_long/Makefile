# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 00:53:18 by eryudi-m          #+#    #+#              #
#    Updated: 2022/10/02 17:19:17 by eryudi-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

#Compile
CC = clang -c
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
VALGRIND =	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#Paths
PATH_APP = ./app
PATH_IMG = ./img
PATH_INC = ./inc
PATH_MAP = ./map
PATH_SRC = ./src
PATH_UTIL = ./util
PATH_LIBFT = ./util/libft/
PATH_OBJ = ./obj

#MLXFLAGS = -lmlx -lXext -lX11

SRC_FILES = load_map.c

SOURCES = $(addprefix $(PATH_SRC), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

#Bash commandas
MKDIR = mkdir -p
RM = rm -f

#TARGETS
all: libft ($NAME)

libft:
	cd $(PATH_LIBFT) && $(MAKE) all

$(NAME): $(OBJECTS)
	cp $(PATH_LIBFT)/libft.a $(PATH_UTIL)$NAME



$(PATH_OBJ)%.o : $(PATH_SRC).c $(PATH_INC)*.h
	$(MKDIR) $(PATH_OBJ)
#$(CC) $(FLAGS) $(MLXFLAGS) -c %< -I $(PATH_INC) -o $@
	$(CC) $(FLAGS) -c %< -I $(PATH_INC) -o $@
	$(MAKE) -C
#$(MAKE) -C $(MINILBIX_PATH)

main: ./app/app.c
	@



clean:
	cd $(PATH_LIBFT) && $(MAKE) clean

