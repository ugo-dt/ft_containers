# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/06/04 13:55:44 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT		:=	ft
NAME_STD	:=	std

SRCS_TESTS	:=	tests/main.cpp tests/vector/constructors.cpp tests/vector/iterators.cpp \
				tests/vector/capacity.cpp tests/vector/elem_access.cpp tests/vector/modifiers.cpp \
				tests/vector/allocator.cpp tests/vector/operators.cpp \
				tests/stack/constructor.cpp tests/stack/functions.cpp \
				tests/map/map.cpp

SRCS		:= 	srcs/internal/rb_tree.cpp $(SRCS_TESTS)

OBJS		:= $(SRCS:.cpp=.o)
HEADERS		:= -I include -I include/internal

CC			:= c++
CFLAGS		:= -Wall -Werror -Wextra -std=c++98

all: $(NAME_FT)

$(NAME_FT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME_FT)

compile: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_STD): clean
	@make compile NAME=$(NAME_STD) namespace=-DSTD

.cpp.o:
	$(CC) $(CFLAGS) $(HEADERS) $(namespace) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME_FT) $(NAME_STD)

re: fclean all

test:
	@bash ./tests/test.sh

.PHONY: all compile clean fclean re test_vector test_stack test_map test
