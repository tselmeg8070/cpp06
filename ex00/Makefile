NAME = run
CXX = c++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = 	ScalarConverter.cpp \
		helpers.cpp \
		main.cpp

INCLS = ScalarConverter.hpp \
		helpers.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(VFLAGS) -o $(NAME) $^

%.o : %.cpp $(INCLS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
