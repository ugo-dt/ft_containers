/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:49:14 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/04 17:57:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/tests_vector.hpp"
#include "stack/tests_stack.hpp"
#include "map/tests_map.hpp"
#include "set/tests_set.hpp"
#include <cstring>

static inline
void	test_stack()
{
	std::cout << ">>> Container: stack <<<" << std::endl;
	tests_stack_constructor();
	tests_stack_functions();
}

static
void test_vector(const char *s)
{
	std::cout << ">>> Container: vector <<<" << std::endl;
	if (s)
	{
		if (strcmp(s, "all") == 0)
			goto vector_all;
		if (strcmp(s, "constructors") == 0 || strcmp(s, "constructor") == 0)
			tests_vector_constructors();
		else if (strcmp(s, "iterators") == 0 || strcmp(s, "iterator") == 0)
			tests_vector_iterators();
		else if (strcmp(s, "capacity") == 0)
			tests_vector_capacity();
		else if (strcmp(s, "access") == 0 || strcmp(s, "element") == 0 || strcmp(s, "element_access") == 0)
			tests_vector_elem_access();
		else if (strcmp(s, "modifiers") == 0 || strcmp(s, "modifier") == 0)
			tests_vector_modifiers();
		else if (strcmp(s, "allocator") == 0)
			tests_vector_allocator();
		else if (strcmp(s, "operators") == 0 || strcmp(s, "operator") == 0)
			tests_vector_operators();
		return ;
	}
	vector_all:
	tests_vector_constructors();
	tests_vector_iterators();
	tests_vector_capacity();
	tests_vector_elem_access();
	tests_vector_modifiers();
	tests_vector_allocator();
	tests_vector_operators();
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "available tests: vector, stack, map" << std::endl
#ifdef STD
			<< "'./std all' for all tests in a row" << std::endl;
#else
			<< "'./ft all' for all tests in a row" << std::endl;
#endif
		return (0);
	}
	else
	{
		if (strcmp(av[1], "all") == 0)
			goto all_tests;
		if (strcmp(av[1], "vector") == 0)
			test_vector(av[2]);
		else if (strcmp(av[1], "stack") == 0)
			test_stack();
		else if (strcmp(av[1], "map") == 0)
			test_map();
		else
			std::cout << "available tests: vector, stack, map" << std::endl;
		return (0);
	}
	{
		all_tests:
		test_vector(NULL);
		test_stack();
		test_map();
	}
	return (0);
}
