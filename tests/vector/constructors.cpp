/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/08 15:10:18 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	test_constructor(NAMESPACE::vector<int>::size_type n = 0, NAMESPACE::vector<int>::value_type x = 0)
{
	NAMESPACE::vector<int> v(n, x, std::allocator<int>());
	std::cout << "> Created new vector with size of " << n << std::endl;
	std::cout << "size:     " << v.size() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "-------------" << std::endl;
}

void	tests_vector_constructors(void)
{
	std::cout << ">>> CONSTRUCTORS <<<" << std::endl;
	{		
		test_constructor(0, 0);
		test_constructor(1);
		test_constructor(100);
		std::cout << "-------------" << std::endl;
		std::cout << ">> operator=" << std::endl;
		NAMESPACE::vector<int> v1(24, 72);
		std::cout << "> Created new vector v1 with size of " << 24 << std::endl;
		v1.reserve(36);
		std::cout << "Allocated more storage for v1 (36)" << std::endl;
		NAMESPACE::vector<int> v2(v1);
		std::cout << "> Created new vector v2 with copy constructor on v1" << std::endl;
		NAMESPACE::vector<int> v3;
		std::cout << "> Created new empty vector v3" << std::endl;
		v3 = v2;
		std::cout << "Copied v2 into v3 with operator= overload" << std::endl;
		std::cout << "-------------" << std::endl << ">> Comparison: " << std::endl;
		std::cout << "size v1:     " << v1.size() << std::endl;
		std::cout << "size v2:     " << v2.size() << std::endl;
		std::cout << "size v3:     " << v3.size() << std::endl;
		std::cout << "max_size v1: " << v1.max_size() << std::endl;
		std::cout << "max_size v2: " << v2.max_size() << std::endl;
		std::cout << "max_size v3: " << v3.max_size() << std::endl;
		std::cout << "capacity v1: " << v1.capacity() << std::endl;
		std::cout << "capacity v2: " << v2.capacity() << std::endl;
		std::cout << "capacity v3: " << v3.capacity() << std::endl;
		std::cout << "-------------" << std::endl;
		std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
		std::cout << "v2 == v3: " << (v2 == v3) << std::endl;
		std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	}
}
