/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 10:55:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vector_constructors()
{
	std::cout << ">>> CONSTRUCTORS <<<" << std::endl;
	{
		print_vector(NAMESPACE::vector<int>(0, 0, std::allocator<int>()), 0);
		print_vector(NAMESPACE::vector<int>(1), 0);
		print_vector(NAMESPACE::vector<int>(100), 0);
		std::cout << ">> operator=" << std::endl;
		NAMESPACE::vector<int> v1(24, 72);
		std::cout << "> Created new vector v1 with size of " << 24 << std::endl;
		v1.reserve(36);
		std::cout << "> Allocated more storage for v1 (36)" << std::endl;
		NAMESPACE::vector<int> v2(v1);
		std::cout << "> Created new vector v2 with copy constructor on v1" << std::endl;
		NAMESPACE::vector<int> v3;
		std::cout << "> Created new empty vector v3" << std::endl;
		v3 = v2;
		std::cout << "> Copied v2 into v3 with operator= overload" << std::endl;
		std::cout << "-------------" << std::endl << ">> Comparison: " << std::endl;
		std::cout << "v1:" << std::endl;
		print_vector(v1, 0);
		std::cout << "v2:" << std::endl;
		print_vector(v2, 0);
		std::cout << "v3:" << std::endl;
		print_vector(v3, 0);
		std::cout << "-------------" << std::endl;
		std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
		std::cout << "v2 == v3: " << (v2 == v3) << std::endl;
		std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
		std::cout << "-------------" << std::endl;
	}
	{

	}
}
