/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/10 15:09:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

void	tests_vector_constructors()
{
	std::cout << ">> vector: constructors" << std::endl;
	{
		std::cout << "> default" << std::endl;
		print_vector(NAMESPACE::vector<int>(), 0);
		print_vector(NAMESPACE::vector<int>(std::allocator<int>()), 0);
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> fill" << std::endl;	
		print_vector(NAMESPACE::vector<int>(3), 0);
		print_vector(NAMESPACE::vector<int>(7, 42), 0);
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> range" << std::endl;
		NAMESPACE::vector<int>	v(5);
		for (int i = 0; i < 5; i++)
			v[i] = i * 2;
		print_vector(v, 0);
		print_vector(NAMESPACE::vector<int>(v.begin() + 1, v.end()), 0);
		print_vector(NAMESPACE::vector<int>(v.begin() + 2, v.end() - 2), 0);
		std::cout << "-------------------" << std::endl;
		std::cout << "> copy" << std::endl;
		print_vector(v, 0);
		print_vector(NAMESPACE::vector<int>(v), 0);
		std::cout << "-------------------" << std::endl;
		std::cout << "> operator=" << std::endl;
		NAMESPACE::vector<int>	v2;
		NAMESPACE::vector<int>	v3(5, 4);
		v2 = v3 = v;
		print_vector(v, 0);
		print_vector(v2, 0);
		print_vector(v3, 0);
		std::cout << "-------------------" << std::endl;
	}
}
