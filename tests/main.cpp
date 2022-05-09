/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:49:14 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 18:25:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/tests_vector.hpp"
#include "stack/tests_stack.hpp"
#include "map/tests_map.hpp"

static inline
void test_vector(char *s)
{
	std::cout << ">>> Container: vector <<<" << std::endl;
	if (s)
	{
		if (strcmp(s, "constructors") == 0 || strcmp(s, "constructor") == 0)
			tests_vector_constructors();
		else if (strcmp(s, "iterators") == 0 || strcmp(s, "iterator") == 0)
			tests_vector_iterators();
		else if (strcmp(s, "capacity") == 0)
			tests_vector_capacity();
		return ;
	}
	tests_vector_constructors();
	tests_vector_iterators();
	tests_vector_capacity();
}

int	main(int ac, char **av)
{
#ifdef STD
	std::cout << "Testing with std" << std::endl;
#else
	std::cout << "Testing with ft" << std::endl;
#endif
	if (ac == 1)
	{
		std::cout << "available tests: vector, stack, map" << std::endl
			<< "'./ft.out all' for all tests in a row" << std::endl;
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
