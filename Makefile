# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/05/08 15:20:01 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft.out
NAME_STD	:= std.out

SRCS		:= tests/vector/main.cpp tests/vector/constructors.cpp

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
	rm -rf $(NAME) $(NAME_STD) ft std

re: fclean all

test: fclean all
	@./$(NAME) > ft
	$(CC) $(FLAGS) -DSTD -std=c++98 -DST $(HEADERS) -c tests/vector/main.cpp -o tests/vector/main.o
	$(CC) $(FLAGS) $(HEADERS) -c tests/vector/constructors.cpp -o tests/vector/constructors.o
	$(CC) $(FLAGS) tests/vector/main.o tests/vector/constructors.o -o $(NAME_STD)
	@./$(NAME_STD) > std
	@(diff -I '^Testing with.*' std ft && echo "Test OK" ) || echo "Test KO"
	@make -s fclean

.PHONY: all clean fclean re
