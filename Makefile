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
pf_print_tools.c

ALL_S = $(SOURCES:.c=$(DIR).c)

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