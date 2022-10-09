# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 03:11:53 by eryudi-m          #+#    #+#              #
#    Updated: 2022/10/04 04:56:21 by eryudi-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#it should get the bin on so_long, and test here

CC = clang -g3
MLXFLAGS = -lmlx -lXext -lX11

TESTS_FILES = validate_extension.c \
		ck_retangle.c \
		ck_border.c \
		ck_elements.c \


PATH_TEST = ./test/
TESTS = $(addprefix $(PATH_TEST), $(TESTS_FILES))

TESTER = ./unity/src/unity.c

MAIN = test_solong.h test_solong.c

FILE = ../so_long/util/so_long

all:
	$(CC) $(TESTS) $(TESTER) $(MAIN) $(FILE) $(MLXFLAGS)
	./a.out

