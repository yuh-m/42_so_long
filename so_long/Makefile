# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 00:53:18 by eryudi-m          #+#    #+#              #
#    Updated: 2022/10/16 10:51:17 by eryudi-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#Compile
CC = clang -g
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
#DEBUG = -g3
MLXFLAGS = -lmlx -lXext -lX11
#-lm -lz -L/usr/lib

#Debugging
VALGRIND =	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
DEBUGGER = gdb

#Paths
PATH_INC = ./inc/
PATH_SRC = ./src/
PATH_UTIL = ./util/
PATH_LIBFT = ./util/libft/
PATH_OBJ = ./obj/
PATH_BIN = ./bin/

#MAPS File
MAP = ./map/map1.ber
#MAP = ./map/map_path1.ber
#MAP = ./map/map2.ber
#MAP = ./map/map3.ber

#map debbug
#MAP = ../test/map/no_rectangle.ber
#MAP = ../test/map/empty_line.ber
#MAP = ../test/map/emptymap.ber
#MAP = ../test/map/other_char.ber
#MAP = ../test/map/no_path.ber
#MAP = ../test/map/no_path_collectible.ber


#Files
SRC_FILES = so_long.c \
			validate_map.c \
			validate_extension.c \
			validate_path.c \
			load_map.c \
			load_sprite.c \
			draw_map.c \
			player_movement.c \
			handle.c \
			exit.c


SOURCES = $(addprefix $(PATH_SRC), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(PATH_OBJ), $(OBJ_FILES))


#Bash commandas
MKDIR = mkdir -p
RM = rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory


#TARGETS
all: libft $(NAME)

libft:
	@cd $(PATH_LIBFT) && $(MAKE_NOPRINT)

$(NAME): $(OBJECTS)
#develop - the copy only happens if there is a change on libt
	@cp $(PATH_LIBFT)libft.a $(PATH_UTIL)$(NAME)
	@ar -rcs $(PATH_UTIL)so_long $(OBJECTS)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(PATH_INC)*.h
	mkdir -p $(PATH_OBJ)
	$(CC) $(FLAGS) -c $< -o $@

#Create executable file
main: ./app/app.c
	@$(MKDIR) $(PATH_BIN)
	@$(CC) $(FLAGS) $(OBJECTS) $(MLXFLAGS) $< $(PATH_UTIL)$(NAME) -I$(PATH_INC) -o $(PATH_BIN)$(NAME)

#Create and load executable file
run: all main
	@$(PATH_BIN)$(NAME) $(MAP)



#Debbuging tools
leak:./app/app.c
	$(CC) $(DEBUG) $(FLAGS) $(OBJECTS) $(MLXFLAGS) $< $(PATH_UTIL)$(NAME) -I$(PATH_INC) -o $(PATH_BIN)$(NAME)
	$(VALGRIND) $(PATH_BIN)$(NAME) $(MAP)

leaks:
	$(VALGRIND) $(PATH_BIN)$(NAME) $(MAP)

gdb: ./app/app.c
	$(CC) $(DEBUG) $(FLAGS) $(OBJECTS) $(MLXFLAGS) $< $(PATH_UTIL)$(NAME) -I$(PATH_INC) -o $(PATH_BIN)$(NAME)
	$(DEBUGGER) $(PATH_BIN)$(NAME)
#set args map


#Delete compiled files
clean:
	@cd $(PATH_LIBFT) && $(MAKE) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@cd $(PATH_LIBFT) && $(MAKE) fclean
	@$(RM) $(PATH_BIN)$(NAME)
	@$(RM) $(PATH_UTIL)$(NAME)

re: fclean all

.PHONY: all clean fclean re
