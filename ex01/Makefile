NAME = a.out
SRCS = main.cpp			Fixed.cpp
OBJS = $(SRCS:%.cpp=objects/%.o)
CXX = c++
CFXXLAGS = -Wall -Wextra -Werror -std=c++98 -ML -LDD

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

objects/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objects
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$<

.PHONY: all clean fclean re run

.DEFAULT_GOAL = all
