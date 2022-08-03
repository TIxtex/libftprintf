NAME = libftprintf.a
CC = gcc -std=c89
CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft/libft.h printf.h
SOURCES = printf.c \
pf_print.c \
pf_print_b.c \
pf_flag.c \
pf_flag_b.c \
pf_print_tools.c

OBJECTS = $(SOURCES:.c=.o)

$(MAKE_OBJECTS_LFT): $(INCLUDE)
	cd libft && make
	OBJECTS_LFT=$(make list_objects)
	cd ..

.PHONY: all clean fclean f re

$(NAME): $(INCLUDE) $(OBJECTS)
	cd libft && make && OBJECTS_LFT=/bin/sh make list_objects
	OBJECTS_LFTA=$(OBJECTS_LFT:.=libft/.)
	cd ..
	ar rc $(NAME) $(OBJECTS) $(OBJECTS_LFTA)
	ranlib $(NAME)

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	cd libft && make clean
	cd ..
fclean: clean
	/bin/rm -rf $(NAME)
	cd libft && make fclean
	cd ..
f: fclean
re: fclean all