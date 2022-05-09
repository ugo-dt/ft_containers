/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:12:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 10:47:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vector_iterators()
{
	std::cout << ">>> ITERATORS <<<" << std::endl;
	NAMESPACE::vector<int> v(0, 0, std::allocator<int>());
	NAMESPACE::vector<int>::iterator				it;
	NAMESPACE::vector<int>::const_iterator			cit;
	NAMESPACE::vector<int>::reverse_iterator		rit;
	NAMESPACE::vector<int>::const_reverse_iterator	crit;

	for (int i = 0; i < 5; i++)
		v.push_back(i);
	print_vector(v);

	std::cout << "-------------" << std::endl << "> iterator" << std::endl;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "--------" << std::endl << "> const_iterator" << std::endl;
	for (cit = v.begin(); cit != v.end(); cit++)
		std::cout << *cit << std::endl;

	std::cout << "--------" << std::endl << "> reverse_iterator" << std::endl;
	for (rit = v.rbegin(); rit != v.rend(); rit++)
		std::cout << *rit << std::endl;

	std::cout << "--------" << std::endl << "> const_reverse_iterator" << std::endl;
	for (crit = v.rbegin(); crit != v.rend(); crit++)
		std::cout << *crit << std::endl;
}
