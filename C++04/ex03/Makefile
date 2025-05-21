NAME = AMateria

SRC = main.cpp IMateriaSource.cpp MateriaSource.cpp AMateria.cpp Cure.cpp Ice.cpp ICharacter.cpp Character.cpp
OBJ = $(SRC:.cpp=.o)

CCA = c++ -std=c++98 -Werror -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CCA) $(OBJ) -o $(NAME)
	@printf "Build Complete !\n"

%.o: %.cpp
	@$(CCA) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@printf "Objects Cleaned !\n"

fclean:
	@rm -f $(OBJ) $(NAME)
	@printf "Cleaned !\n"

re: fclean all

.PHONY: all clean fclean re
