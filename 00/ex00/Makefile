# result file name
NAME = megaphone

# compiler
CC = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDXXFLAGS =

SRCS = main.cc

OBJS = $(SRCS:.cpp=.o) $(SRCS:.cc=.o)

all: $(NAME)

%.o : %.cc, %.cpp
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

# result file name
NAME = ./philo

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

