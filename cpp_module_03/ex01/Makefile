CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = FragTrap
ifdef DEBUG
	CPPFLAGS += -g3 -fsanitize=address
endif

SRCS = main.cpp ClapTrap.cpp FragTrap.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = ClapTrap.hpp FragTrap.hpp

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
