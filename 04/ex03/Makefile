# result file name
NAME = cpp04ex03

# compiler
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDXXFLAGS =

SRCS = main.cpp AMateria.cpp MateriaSource.cpp Character.cpp Cure.cpp Ice.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean re all

