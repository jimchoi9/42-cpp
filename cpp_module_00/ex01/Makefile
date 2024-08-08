CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = PhoneBook

ifdef DEBUG
	CPPFLAGS += -g3 -fsanitize=address
endif

SRCS = main.cpp Contact.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = Contact.hpp PhoneBook.hpp

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


# NAME = PhoneBook
# SRCS = main.cpp Contact.cpp PhoneBook.cpp
# INCS = Contact.hpp PhoneBook.hpp
# OBJ_DIR = objs
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
# CPP = c++
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# all : $(NAME)

# $(NAME) : $(OBJS) $(INCS)
# 	$(CPP) $(CPPFLAGS) -o $@ $^

# $(OBJ_DIR)/%.o : %.cpp
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CPP) $(CPPFLAGS) -c -o $@ $<

# clean :
# 	rm -rf $(OBJ_DIR)

# fclean : clean
# 	rm -rf $(NAME)

# re : fclean all

# .PHONY : all clean fclean re