/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:13:56 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/10 12:59:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <string>

int main(void)
{
	ft::vector<std::string>				a(5, "lol");
	ft::vector<std::string>				b(a);
	ft::vector<std::string>				c;
	ft::vector<std::string>::iterator	it;

	for (it = a.begin(); it != a.end(); it++)
		std::cout << "a: " << (*it = "lal") << std::endl;
	for (it = b.begin(); it != b.end(); it++)
		std::cout << "b: " << *it << std::endl;
	c = b;
	for (it = c.begin(); it != c.end(); it++)
		std::cout << "c: " << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;

	a.resize(3, "salut");
	for (it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;

	std::cout << a.capacity() << std::endl;
	a.assign(4, "xd");
	for (it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	return (0);
}
