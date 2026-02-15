NAME = bsp
SRCS = main.cpp			Fixed.cpp		Point.cpp			bsp.cpp
BUILD = build
OBJS = $(addprefix $(BUILD)/, $(SRCS:%.cpp=%.o))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

all: $(NAME)

$(NAME): $(BUILD) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD):
	mkdir $@

$(BUILD)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$<

.PHONY: all clean fclean re run

.DEFAULT_GOAL = all

-include $(OBJS:%.o=%.d)
