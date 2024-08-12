CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = account

ifdef DEBUG
	CPPFLAGS += -g3 -fsanitize=address
endif

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = Account.hpp

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
