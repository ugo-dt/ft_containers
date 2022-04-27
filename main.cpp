/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:13:56 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/27 18:52:17 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main(void)
{
	ft::vector<std::string>						a(5, "lol");
	ft::vector<std::string>::iterator			it;
	ft::vector<std::string>::const_reverse_iterator	it2;

	a[0] = "salut";
	for (it = a.begin(); it != a.end(); it++)
		std::cout << "a: " << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << "front: " << a.front() << std::endl;
	std::cout << "back: " << a.back() << std::endl;

	a.resize(3, "salut");
	for (it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;

	std::cout << a.capacity() << std::endl;
	a.assign(4, "xd");
	a[0] = "salut";
	a.reserve(34);
	for (it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;

	for (it2 = a.rbegin(); it2 != a.rend(); it2++)
		std::cout << *it2 << std::endl;

	return (0);
}
