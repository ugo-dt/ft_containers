# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:13:05 by ugdaniel          #+#    #+#              #
#    Updated: 2022/05/27 11:44:39 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT		:=	ft.out
NAME_STD	:=	std.out

SRCS_TESTS	:=	tests/main.cpp tests/vector/constructors.cpp tests/vector/iterators.cpp \
				tests/vector/capacity.cpp tests/vector/elem_access.cpp tests/vector/modifiers.cpp \
				tests/vector/allocator.cpp tests/vector/operators.cpp \
				tests/stack/constructor.cpp tests/stack/functions.cpp \
				tests/map/map.cpp

SRCS		:= 	srcs/_rb_tree.cpp $(SRCS_TESTS)

OBJS		:= $(SRCS:.cpp=.o)
HEADERS		:= -I include -I include/_algorithm -I include/_functional -I include/_iterator -I include/_utility

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

test_vector:
	@printf "ft: vector"
	@time ./$(NAME_FT) vector > ft_vector
	@printf "std: vector"
	@time ./$(NAME_STD) vector > std_vector
	@(diff -I '^Testing with.*' ft_vector std_vector && echo "vector OK" && rm -f ft_vector std_vector) || echo "vector KO"

test_stack:
	@printf "\nft: stack"
	@time ./$(NAME_FT) stack > ft_stack
	@printf "std: stack"
	@time ./$(NAME_STD) stack > std_stack
	@(diff -I '^Testing with.*' ft_stack std_stack && echo "stack OK" && rm -f ft_stack std_stack) || echo "stack KO"

test_map:
	@printf "\nft: map"
	@time ./$(NAME_FT) map > ft_map
	@printf "std: map"
	@time ./$(NAME_STD) map > std_map
	@(diff -I '^Testing with.*' ft_map std_map && echo "map OK" && rm -f ft_map std_map) || echo "map KO"

test: $(NAME_FT) $(NAME_STD)
	@printf "\n"
	@make -s test_vector test_stack test_map

.PHONY: all compile clean fclean re test_vector test_stack test_map test
