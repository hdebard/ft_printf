SRC = 	ft_printf.c\
	format_modifier.c\
	fill_list.c\
	select_format.c\
	add_flags.c\
	add_precision_and_width.c\
	get_str.c\
	get_unicode.c\
	utility.c\
	utility2.c\
	util_itoabase.c


OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
