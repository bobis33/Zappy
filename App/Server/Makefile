##
## EPITECH PROJECT, 2024
## Zappy | Server
## File description:
## Makefile
##


SRC = 			src/main.c          \
                src/bind.c          \

OBJ = 			$(SRC:.c=.o)

INCLUDE =       -I./include

CFLAGS = 		-W -Wall -Wextra -Werror $(INCLUDE) -std=c11 -D_GNU_SOURCE

NAME =          zappy_server

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:			$(NAME)

debug:			CFLAGS += -g3 -ggdb
debug:          re

clean:
				rm -f $(OBJ)

fclean:			clean
				$(RM) ../$(NAME)
				find . -name "*.gcda" -delete -or -name "*.gcno" -delete
				find . -name "*.log" -delete

re:				fclean all

.PHONY:			all clean fclean re debug
