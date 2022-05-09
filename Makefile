# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/05/09 11:05:14 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft.out
NAME_STD	:= std.out

SRCS		:= tests/vector/main.cpp tests/vector/constructors.cpp tests/vector/iterators.cpp

OBJS		:= $(SRCS:.cpp=.o)
HEADERS		:= -I .

CC			:= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_STD)

re: fclean all

test: fclean all
	$(CC) $(FLAGS) $(HEADERS) -DSTD -c tests/vector/main.cpp -o tests/vector/main.o
	$(CC) $(FLAGS) $(HEADERS) -c tests/vector/constructors.cpp -o tests/vector/constructors.o
	$(CC) $(FLAGS) $(HEADERS) -c tests/vector/iterators.cpp -o tests/vector/iterators.o
	$(CC) $(FLAGS) $(OBJS) -o $(NAME_STD)
	@./$(NAME) vector > ft
	@./$(NAME_STD) vector > std
	@(diff -I '^Testing with.*' std ft && echo "vector OK" ) || echo "vector KO"
	@./$(NAME) stack > ft
	@./$(NAME_STD) stack > std
	@(diff -I '^Testing with.*' std ft && echo "stack OK" ) || echo "stack KO"
	@./$(NAME) map > ft
	@./$(NAME_STD) map > std
	@(diff -I '^Testing with.*' std ft && echo "map OK" ) || echo "map KO"
	@make -s fclean

.PHONY: all clean fclean re
