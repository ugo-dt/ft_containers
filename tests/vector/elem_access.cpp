/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_access.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/11 21:35:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

void	tests_vector_elem_access()
{
	std::cout << ">> vector: element access" << std::endl;
	{
		std::cout << "> operator[]" << std::endl;
		NAMESPACE::vector<int> v(10); // 10 zero-initialized elements
		NAMESPACE::vector<int>::size_type sz = v.size();
		// assign some values:
		for (unsigned i = 0; i < sz; i++) v[i] = i;
		// reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++)
		{
			int temp = v[sz - 1 - i];
			v[sz - 1 - i] = v[i];
			v[i] = temp;
		}
		std::cout << "v contains:";
		for (unsigned i = 0; i < sz; i++)
			std::cout << ' ' << v[i];
		std::cout << std::endl << "-------------------" << std::endl;
	}
	{
		std::cout << "> at" << std::endl;
		NAMESPACE::vector<int> v(10); // 10 zero-initialized ints
		// assign some values:
		for (unsigned int i = 0; i < v.size(); i++)
			v.at(i)=i;
		std::cout << "v contains:";
		for (unsigned int i = 0; i < v.size(); i++)
			std::cout << ' ' << v.at(i);
		std::cout << std::endl;
		try {std::cout << v.at(4200) << std::endl;}
		catch (std::out_of_range& e) {std::cout << "OK: caught out_of_range exception" << std::endl;}
		catch (...) {std::cout << "KO: expected out_of_range exception" << std::endl;}
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> front" << std::endl;
		NAMESPACE::vector<int> v;
		v.push_back(78);
		v.push_back(16);
		// now front equals 78, and back 16
		v.front() -= v.back();
		std::cout << "v.front() is now " << v.front() << std::endl << "-------------------" << std::endl;
	}
	{
		std::cout << "> back" << std::endl;
		NAMESPACE::vector<int> v;
		v.push_back(10);
		while (v.back() != 0)
			v.push_back(v.back() - 1);
		std::cout << "v contains:";
		for (unsigned int i=0; i < v.size(); i++)
			std::cout << ' ' << v[i];
		std::cout << std::endl << "-------------------" << std::endl;
	}
}
