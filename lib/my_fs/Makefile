##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile de fs lib:
##

SRC =	fs_cat_x_bytes.c				\
		fs_get_number_from_first_line.c	\
		fs_open_file.c					\
		fs_print_first_line.c			\
		fs_understand_return_of_read.c	\
		fs_nb_char_into_file.c			\
		fs_write_control_file.c

OBJ = $(SRC:.c=.o)

NAME = libmy_fs.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my_fs.h ../../include
	cp my_fs.h ../my/

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

debug: CFLAGS += -g3
debug: re