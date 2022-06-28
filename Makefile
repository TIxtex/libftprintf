NAME = libft.a
CC = clang -std=c89
CFLAGS = -Wall -Wextra -Werror -pedantic

INCLUDE = libft.h libftprintf.h
LIBFT = libft/libft.a
DIR = sources/
SOURCES = \

ALL_S = $(SOURCES:%.c=$(DIR)%.c)
OBJECTS = $(ALL_S:.c=.o)

.PHONY: all clean fclean f re

$(NAME): $(LIBFT) $(INCLUDE) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(LIBFT):
	cd libft && make
	cd ..

all: $(NAME)
bonus: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	cd libft && make clean
	cd ..
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
