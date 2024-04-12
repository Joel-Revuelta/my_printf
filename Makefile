##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	=	src/my_printf.c 	\
		src/get_flags.c 	\
		src/create_arg.c 	\
		src/fl_c.c 			\
		src/fl_d.c 			\
		src/fl_prc.c 		\
		src/fl_s.c 			\
		src/fl_x.c 			\
		src/fl_xx.c 		\
		src/fl_u.c 			\
		src/fl_ss.c 		\
		src/fl_b.c 			\
		src/fl_o.c 			\
		src/fl_n.c 			\
		src/fl_p.c 			\
		src/fl_ff.c 		\
		src/fl_g.c 			\
		src/fl_e.c 			\
		src/fl_ee.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS = -W -Wall -Wextra -Werror -I include/ -L lib/ -lmy

TESTS = tests/printf_tests.c

T_NAME = unit_tests

T_FLAGS = -w -Wall -Wextra -Werror -I include/ -L ./ -lmy --coverage -lcriterion

all: 	$(NAME)

$(NAME): dolib $(OBJ)
	ar rc $(NAME) $(OBJ) lib/*.o

dolib:
	cd lib; make

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	cd lib; make clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	cd lib; make fclean

re:	fclean all
	make clean

unit_tests: fclean all
	gcc -o $(T_NAME) $(TESTS) $(T_FLAGS)

tests_run: unit_tests
	./$(T_NAME)
