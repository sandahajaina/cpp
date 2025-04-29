NAME = identify
SRCS = src/main.cpp src/Base.cpp src/A.cpp src/B.cpp src/C.cpp src/functions.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

valgrind : all
	valgrind --leak-check=full ./$(NAME)

.PHONY : all clean fclean re