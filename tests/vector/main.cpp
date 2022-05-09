/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:49:14 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 11:03:59 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_vector()
{
	tests_vector_constructors();
	tests_vector_iterators();
}

int	main(int ac, char **av)
{
#ifdef STD
	std::cout << "Testing with std" << std::endl;
#else
	std::cout << "Testing with ft" << std::endl;
#endif
	if (ac > 1)
	{
		if (strcmp(av[1], "vector") == 0)
			test_vector();
		else
			std::cout << "available tests: vector" << std::endl;
		return (0);
	}
	test_vector();
	return (0);
}
