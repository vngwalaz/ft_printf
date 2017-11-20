# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/18 13:37:24 by vngwalaz          #+#    #+#              #
#    Updated: 2017/06/25 17:27:26 by vngwalaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = libftprintf.a

SRC = ft_hex_oct.c ft_putnbr.c ft_check_c_s.c ft_putstr.c ft_printf.c \
	  ft_putchar.c ft_conveter.c ft_strcmp.c ft_strlen.c ft_itoa.c \
	  ft_strdup.c ft_isdigit.c ft_strsub.c

OBJ = ft_hex_oct.o ft_putnbr.o ft_putstr.o ft_check_c_s.o ft_printf.o \
	  ft_putchar.o ft_conveter.o ft_strcmp.o ft_strlen.o ft_itoa.o \
	  ft_strdup.o ft_isdigit.o ft_strsub.o

HEADER = ./libftprintf.h

FLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc libftprintf.a $(OBJ) $(HEADER)
	ranlib libftprintf.a
	
clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all
