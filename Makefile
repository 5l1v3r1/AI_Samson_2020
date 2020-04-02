##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile de project
##

SRC_DIR	=	src/

FILES = main.c

TEST_DIR = tests/

TESTS_FILES	=	tests.c

SRC =	$(addprefix $(SRC_DIR), $(FILES))

OBJ = $(SRC:.c=.o)

SRC_TEST = $(addprefix $(TEST_DIR), $(TESTS_FILES))

OBJ_TEST = $(SRC_TEST:.c=.o)

LDFLAGS		=	-lcriterion -lgcov --coverage -L$(LIB_DIR)my/ -lmy -L$(LIB_DIR)my_fs/ -lmy_fs

INC_DIR	=	-Iinclude/

LIB_DIR	=	./lib/

CFLAGS 	=	-Wall -Wextra -W $(INC_DIR)

CC	=	gcc

NAME = CHANGE_THE_BINARY_NAME

all : $(NAME)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	make -C ./lib/my debug
	make -C ./lib/my_fs debug
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run: re
tests_run: $(OBJ_TEST)
		gcc -o unit-tests $(LDFLAGS) $(SRC_TEST) ./lib/my/libmy.a ./lib/my_fs/libmy_fs.a $(CFLAGS)
		./unit-tests
		gcov *.gcna
		gcov *.gcno


$(NAME) : $(OBJ)
	cd ./lib/my && make && cd ../../
	cd ./lib/my_fs && make && cd ../../
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
clean :
	cd ./lib/my && make clean && cd ../../
	cd ./lib/my_fs && make clean && cd ../../
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean : clean
	cd ./lib/my && make fclean && cd ../../
	cd ./lib/my_fs && make fclean && cd ../../
	rm -f $(NAME)
	rm -f tests.c.gcov
	rm -f tests.gcda
	rm -f tests.gcno
	rm -f unit-tests

re : fclean all

sweet : all clean
