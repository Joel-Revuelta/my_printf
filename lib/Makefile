##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c 		\
		my_getnbr.c 				\
		my_is_prime.c				\
		my_isneg.c 					\
		my_put_nbr.c 				\
		my_putchar.c 				\
		my_putstr.c 				\
		my_revstr.c 				\
		my_showstr.c 				\
		my_sort_int_array.c 		\
		my_str_isalpha.c 			\
		my_str_islower.c			\
		my_str_isnum.c 				\
		my_str_isprintable.c 		\
		my_str_isupper.c 			\
		my_str_to_word_array.c 		\
		my_strcapitalize.c 			\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_strcpy.c 				\
		my_strdup.c 				\
		my_strlen.c 				\
		my_strlowcase.c 			\
		my_strncat.c 				\
		my_strncmp.c 				\
		my_strncpy.c 				\
		my_strstr.c 				\
		my_strupcase.c 				\
		my_swap.c 					\
		my_strdup_from.c 			\
		my_int_len.c 				\
		my_int_to_str.c 			\
		pos_n.c						\
		my_nbrlen.c					\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../include/

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f ../include/my.h

re:	fclean all
	make clean
