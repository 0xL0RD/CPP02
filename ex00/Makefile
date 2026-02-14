NAME = Canonical
SRCS = main.cpp			Fixed.cpp
OBJS = $(SRCS:%.cpp=%.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

run: $(NAME)
	./$<

.PHONY: all clean fclean re run
