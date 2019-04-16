# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceugene <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:04:25 by ceugene           #+#    #+#              #
#    Updated: 2018/03/12 13:52:00 by ceugene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =		ft_bzero.c			\
			ft_memset.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putnbr.c			\
			ft_atoi.c			\
			ft_atof.c			\
			ft_isdigit.c		\
			ft_isascii.c		\
			ft_strlen.c			\

SRCO =		ft_bzero.o			\
			ft_memset.o			\
			ft_putchar.o		\
			ft_putstr.o			\
			ft_putnbr.o			\
			ft_atoi.o			\
			ft_atof.o			\
			ft_isdigit.o		\
			ft_isascii.o		\
			ft_strlen.o			\

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = compiled_objects

SRC = $(addprefix $(SRCS_PATH)/,$(SRCS))

OBJ = $(addprefix $(OBJ_PATH)/,$(SRCO))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -c $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all
