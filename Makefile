# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/05/11 20:34:36 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft.out
NAME_STD	:= std.out

SRCS		:= tests/main.cpp tests/vector/constructors.cpp tests/vector/iterators.cpp \
				tests/vector/capacity.cpp tests/vector/elem_access.cpp tests/vector/modifiers.cpp \
				tests/vector/allocator.cpp \
				tests/stack/stack.cpp tests/map/map.cpp

OBJS		:= $(SRCS:.cpp=.o)
HEADERS		:= -I .

CC			:= c++
CFLAGS		:= -Wall -Werror -Wextra -std=c++98

all: $(NAME) $(NAME_STD)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_STD)

re: fclean all

$(NAME_STD):
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/main.cpp -o tests/main.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/constructors.cpp -o tests/vector/constructors.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/iterators.cpp -o tests/vector/iterators.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/capacity.cpp -o tests/vector/capacity.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/elem_access.cpp -o tests/vector/elem_access.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/modifiers.cpp -o tests/vector/modifiers.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/vector/allocator.cpp -o tests/vector/allocator.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/stack/stack.cpp -o tests/stack/stack.o
	$(CC) $(CFLAGS) $(HEADERS) -DSTD -c tests/map/map.cpp -o tests/map/map.o
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME_STD)

test: fclean $(NAME) $(NAME_STD)
	@./$(NAME) vector > ft_vector
	@./$(NAME_STD) vector > std_vector
	@(diff -I '^Testing with.*' ft_vector std_vector && echo "vector OK" && rm -f ft_vector std_vector) || echo "vector KO"
	@./$(NAME) stack > ft_stack
	@./$(NAME_STD) stack > std_stack
	@(diff -I '^Testing with.*' ft_stack std_stack && echo "stack OK" && rm -f ft_stack std_stack) || echo "stack KO"
	@./$(NAME) map > ft_map
	@./$(NAME_STD) map > std_map
	@(diff -I '^Testing with.*' ft_map std_map && echo "map OK" && rm -f ft_map std_map) || echo "map KO"
	@make -s fclean

.PHONY: all clean fclean re
