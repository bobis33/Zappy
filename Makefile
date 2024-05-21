##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

AI = App/AI

GUI = App/GUI

Server = App/Server

all: server gui

server:
	@make -C $(Server)

gui:
	cd App/GUI && ./build.sh build

clean:
	cd App/GUI && ./build.sh clean
	@make clean -C $(Server)

fclean:
	cd App/GUI && ./build.sh clean
	@make fclean -C $(Server)

re: fclean all

.PHONY: all clean fclean re