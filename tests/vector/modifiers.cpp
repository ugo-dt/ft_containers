/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/11 18:51:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

void	tests_vector_modifiers()
{
	std::cout << ">> vector: modifiers" << std::endl;
	{
		std::cout << "> assign" << std::endl;
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign(7,100); // 7 ints with a value of 100
		std::vector<int>::iterator it;
		it = first.begin()+1;
		second.assign(it,first.end() - 1); // the 5 central values of first
		int ints[] = {1776,7,4};
		third.assign(ints, ints + 3); // assigning from array.
		std::cout << "Size of first: " << int(first.size()) << std::endl;
		std::cout << "Size of second: " << int(second.size()) << std::endl;
		std::cout << "Size of third: " << int(third.size()) << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> push_back" << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 42; i++)
			v.push_back(i * 42);
		std::cout << "v stores " << int(v.size()) << " numbers." << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> pop_back" << std::endl;
		std::vector<int> v;
		int sum(0);
		v.push_back(100);
		v.push_back(200);
		v.push_back(300);
		while (!v.empty())
		{
			sum += v.back();
			v.pop_back();
		}
		std::cout << "The elements of v add up to " << sum << '\n';
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> insert" << std::endl;
		std::vector<int> v(3,100);
		std::vector<int>::iterator it;
		it = v.begin();
		it = v.insert(it, 200);
		v.insert(it, 2, 300);
		it = v.begin(); // iterator no longer valid, we get a new one
		std::vector<int> v2(2,400);
		v.insert(it + 2, v2.begin(), v2.end());
		int myarray [] = {501, 502, 503};
		v.insert(v.begin(), myarray, myarray + 3);
		std::cout << "v contains:";
		for (it = v.begin(); it != v.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> erase" << std::endl;
		std::vector<int> v;
		// set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			v.push_back(i);
		// erase the 6th element
		v.erase(v.begin()+5);
		// erase the first 3 elements:
		v.erase(v.begin(), v.begin() + 3);
		std::cout << "v contains:";
		for (unsigned i = 0; i < v.size(); ++i)
			std::cout << ' ' << v[i];
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> swap" << std::endl;
		std::vector<int> foo(3,100); // three ints with a value of 100
		std::vector<int> bar(5,200); // five ints with a value of 200
		foo.swap(bar);
		std::cout << "foo contains:";
		for (unsigned i = 0; i < foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << std::endl;
		std::cout << "bar contains:";
		for (unsigned i = 0; i < bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
	}
	{
		std::cout << "> clear" << std::endl;
		std::vector<int> v;
		v.push_back(100);
		v.push_back(200);
		v.push_back(300);

		std::cout << "v contains:";
		for (unsigned i = 0; i < v.size(); i++)
			std::cout << ' ' << v[i];
		std::cout << std::endl;
		v.clear();
		v.push_back(1101);
		v.push_back(2202);
		std::cout << "v contains:";
		for (unsigned i = 0; i < v.size(); i++)
			std::cout << ' ' << v[i];
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
	}
}
