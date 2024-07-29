##
## EPITECH PROJECT, 2024
## B-CCP-400-MAR-4-1-panoramix-matthieu.bousquet
## File description:
## Makefile
##

SRC		=	$(shell find ./ -type f -name "*.cpp")

NAME	=	plazza

FLAGS	=	-W -Wall -Wextra -g3

LIBS 	= 	-lpthread -lrt

all:
	g++ $(SRC) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
