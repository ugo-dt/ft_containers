# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/05/13 17:54:07 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT		:= ft.out
NAME_STD	:= std.out

SRCS		:= tests/main.cpp tests/vector/constructors.cpp tests/vector/iterators.cpp \
				tests/vector/capacity.cpp tests/vector/elem_access.cpp tests/vector/modifiers.cpp \
				tests/vector/allocator.cpp \
				tests/stack/constructor.cpp tests/stack/functions.cpp \
				tests/map/map.cpp

OBJS		:= $(SRCS:.cpp=.o)
HEADERS		:= -I .

CC			:= c++
CFLAGS		:= -Wall -Werror -Wextra -std=c++98

all: $(NAME_FT) $(NAME_STD)

$(NAME_FT):
	@make -s clean
	@make compile NAME=$(NAME_FT)

$(NAME_STD):
	@make -s clean
	@make compile NAME=$(NAME_STD) namespace=-DSTD

compile: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) $(HEADERS) $(namespace) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME_FT) $(NAME_STD)

re: fclean all

test_vector:
	@./$(NAME_FT) vector > ft_vector
	@./$(NAME_STD) vector > std_vector
	@(diff -I '^Testing with.*' ft_vector std_vector && echo "vector OK" && rm -f ft_vector std_vector) || echo "vector KO"

test_stack:
	@./$(NAME_FT) stack > ft_stack
	@./$(NAME_STD) stack > std_stack
	@(diff -I '^Testing with.*' ft_stack std_stack && echo "stack OK" && rm -f ft_stack std_stack) || echo "stack KO"

test_map:
	@./$(NAME_FT) map > ft_map
	@./$(NAME_STD) map > std_map
	@(diff -I '^Testing with.*' ft_map std_map && echo "map OK" && rm -f ft_map std_map) || echo "map KO"

test: $(NAME_FT) $(NAME_STD)
	@make -s test_vector test_stack test_map

.PHONY: all clean fclean re
