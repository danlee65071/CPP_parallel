NAME = hw4

SRCS = hw4.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CC = clang++

FLAGS = -Xpreprocessor -fopenmp -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(FLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re