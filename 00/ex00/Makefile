# result file name
NAME = megaphone

# compiler
CC = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDXXFLAGS =

SRCS = main.cc

OBJS = $(SRCS:.cc=.o)

all: $(NAME)

%.o : %.cc
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

