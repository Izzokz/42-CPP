NAME = Serializer
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CPP = c++ -std=c++98 -Werror -Wextra -Wall -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(OBJ) -o $(NAME)
	@printf "Build Complete !\n"

%.o: %.cpp
	@$(CPP) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@printf "Objects Cleaned !\n"

fclean:
	@rm -f $(OBJ) $(NAME)
	@printf "Cleaned !\n"

re: fclean all

.PHONY: all clean fclean re
