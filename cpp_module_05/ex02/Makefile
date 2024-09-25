CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Bureaucrat

ifdef DEBUG
	CPPFLAGS += -g3 -fsanitize=address
endif

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

INCS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS)  -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CPP)  $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)
	rm *_shrubbery
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
