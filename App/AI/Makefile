##
## EPITECH PROJECT, 2024
## Zappy | AI
## File description:
## Makefile
##

SRC			=		App/src/main.py \

NAME        =       zappy_ai

all:				$(SRC)
					@cp $(SRC) $(NAME)
					@chmod +x $(NAME)

clean:
					rm -rf $(NAME)

fclean:				clean

re:					fclean all

.PHONY:				all clean fclean re