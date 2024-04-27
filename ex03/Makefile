CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD -g

SRC		=	main.cpp \
			class/Bureaucrat.cpp \
			class/AForm.cpp \
			class/PresidentialPardonForm.cpp \
			class/RobotomyRequestForm.cpp \
			class/ShrubberyCreationForm.cpp \
			class/Intern.cpp \

OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

OBJ_DIR	=	$(sort $(dir $(OBJ)))

HEADER	=	-Iclass

NAME	=	Bureaucrat

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADER) $^ -o $@ -c

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re

