# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:21:16 by uliherre          #+#    #+#              #
#    Updated: 2022/09/12 00:51:59 by uliherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -std=c89
CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft/libft.h ft_printf.h

LIB = libft/

DIR = sources/

SOURCES = printf.c \
pf_print.c \
pf_print_b.c \
pf_flag.c \
pf_flag_b.c \
pf_print_tools.c \
ft_utoa.c

ALL_S = $(SOURCES:%.c=$(DIR)%.c)

OBJECTS = $(ALL_S:.c=.o)

.PHONY: all clean fclean f re

$(NAME): $(INCLUDE) $(OBJECTS)
	make -C $(LIB)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)
bonus: $(NAME)
clean:
	@/bin/rm -rf $(OBJECTS)
	@make clean -C $(LIB)
fclean: clean
	@/bin/rm -rf $(NAME)
	@make fclean -C $(LIB)
f: fclean
re: f all