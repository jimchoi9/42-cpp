CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Materia

ifdef DEBUG
	CPPFLAGS += -g3 -fsanitize=address
endif

SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp IMateriaSource.cpp ICharacter.cpp
OBJS = $(SRCS:.cpp=.o)

INCS = Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp AMateria.hpp IMateriaSource.hpp ICharacter.hpp

%.o: %.cpp
	$(CPP) $(CPPFLAGS)  -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CPP)  $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
