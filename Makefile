##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

AI 			= App/AI

GUI 		= App/GUI

Server 		= App/Server

all:        ai gui server

ai:
			@make -C $(AI)

gui:
			cd $(GUI) && ./build.sh build

server:
			cd $(Server) && ./build.sh build

clean:
			@make clean -C $(AI)
			cd $(GUI) && ./build.sh clean
			cd $(Server) && ./build.sh clean

fclean:
			@make fclean -C $(AI)
			cd $(GUI) && ./build.sh clean
			cd $(Server) && ./build.sh clean

re: 		fclean all

.PHONY: 	all ai gui server clean fclean re
