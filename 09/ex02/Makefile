# result file name
NAME = PmergeMe

# compiler
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDXXFLAGS = main.cpp PmergeMe.cpp PmergeMeVector.cpp

SRCS =

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

