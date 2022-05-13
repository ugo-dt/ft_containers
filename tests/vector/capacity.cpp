/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/13 13:28:34 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

void	tests_vector_capacity()
{
	{
		std::cout << ">> vector: capacity" << std::endl;
		NAMESPACE::vector<int>	v;

		std::cout << "empty: " << v.empty() << std::endl;
		print_vector(v);
		std::cout << "> Pushed back 1 element" << std::endl;
		v.push_back(1);
		print_vector(v);
		std::cout << "> Resized to 5" << std::endl;
		v.resize(5, 42);
		print_vector(v);
		std::cout << "> Resized to 3" << std::endl;
		v.resize(3, 21);
		print_vector(v);
		std::cout << "empty: " << v.empty() << std::endl;
		v.reserve(20);
		std::cout << "> Reserved a size of 20" << std::endl;
		print_vector(v);
		try {v.reserve(v.max_size() + 1);}
		catch (std::length_error& e) {std::cout << "OK: caught length_error exception" << std::endl;}
		catch (...) {std::cout << "KO: expected length_error exception" << std::endl;}
		std::cout << "-------------------" << std::endl;
	}
}
