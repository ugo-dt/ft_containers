/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:22:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/14 19:35:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

template <class T, class Alloc>
void	cmp(const NAMESPACE::vector<T, Alloc> &lhs, const NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "> [" << i++ << "]" << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs < rhs)  << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs > rhs)  << " | ge: " << (lhs >= rhs) << std::endl;
}

void	tests_vector_operators()
{
	std::cout << "> vector: operators" << std::endl;
	NAMESPACE::vector<int> vct(4);
	NAMESPACE::vector<int> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7
}
