/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:38:35 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/11 21:03:34 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_stack.hpp"

void	tests_stack_constructor()
{
	std::cout << ">> stack: constructor" << std::endl;
	NAMESPACE::vector<int> v(42, 42); // vector with 2 elements
	NAMESPACE::stack<int> first;      // empty stack
	NAMESPACE::stack<int, NAMESPACE::vector<int> > second; // empty stack using vector
	NAMESPACE::stack<int, NAMESPACE::vector<int> > third(v);

	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "size of third: " << third.size() << std::endl;
	std::cout << "-------------------" << std::endl;
}
