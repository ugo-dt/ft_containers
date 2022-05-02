/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:13:56 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/02 21:05:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#ifdef STD
# define NAMESPACE	std
#else
# define NAMESPACE	ft
#endif

int main(void)
{
	NAMESPACE::vector<int>						v;
	NAMESPACE::vector<int>						v2(0);
	NAMESPACE::vector<int>::iterator			it;
	NAMESPACE::vector<int>::reverse_iterator	rit;
	NAMESPACE::vector<int>::size_type			ref;

	v.push_back(1);
	v.push_back(42);
	v.push_back(100);
	v.push_back(-789);
	std::cout << "> Pushed back 4 elements" << std::endl;

	std::cout << "size:\t  " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty:\t  " << v.empty() << std::endl;
	std::cout << "max_size:\t  " << v.max_size() << std::endl;

	std::cout << "------------" << std::endl;
	std::cout << "iterator" << std::endl;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "reverse iterator" << std::endl;
	for (rit = v.rbegin(); rit != v.rend(); rit++)
		std::cout << *rit << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "reference" << std::endl;
	for (ref = 0; ref < v.size(); ref++)
		std::cout << v[ref] << std::endl;
	while (ref--)
		std::cout << v[ref] << std::endl;

	std::cout << "------------" << std::endl;
	v.reserve(50);
	std::cout << "> reserved 50" << std::endl;
	std::cout << "size:\t  " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty:\t  " << v.empty() << std::endl;
	std::cout << "max_size:\t  " << v.max_size() << std::endl;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
	v.assign((size_t)3, 33);
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "> operator[]" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << v[i] << std::endl;
	std::cout << "> at" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << v.at(i) << std::endl;
	std::cout << "> front: " << v.front() << std::endl;
	std::cout << "> back: " << v.back() << std::endl;
	std::cout << "------------" << std::endl;
	v.pop_back();
	std::cout << "> pop_back, insert begin" << std::endl;
	v.insert(v.begin(), 20);
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "------------" << std::endl;

	v.clear();
	std::cout << "> clear member function called" << std::endl;
	std::cout << "size:\t  " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty:\t  " << v.empty() << std::endl;

	std::cout << "------------" << std::endl;
	v.swap(v2);
	std::cout << "> swap member function called with an empty vector" << std::endl;
	std::cout << "size:\t  " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty:\t  " << v.empty() << std::endl;
	return (0);
}
