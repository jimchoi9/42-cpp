CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS)  -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CPP)  $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# NAME = megaphone
# SRCS = main.cpp
# OBJ_DIR = objs
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
# CPP = c++
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# all : $(NAME)

# $(NAME) : $(OBJS)
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