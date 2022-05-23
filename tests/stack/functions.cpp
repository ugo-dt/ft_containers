/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:02:35 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/23 15:20:59 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_stack.hpp"

void	tests_stack_functions()
{
	std::cout << ">> member functions" << std::endl;
	{
		std::cout << "> empty" << std::endl;
		std::stack<int> s;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			s.push(i);

		while (!s.empty())
		{
			sum += s.top();
			s.pop();
		}
		std::cout << "total: " << sum << std::endl << "-------------------" << std::endl;
	}
	{
		std::cout << "> size" << std::endl;
		std::stack<int> s;
		std::cout << "0. size: " << s.size() << std::endl;
		for (int i=0; i<50000000; i++)
			s.push(i);
		std::cout << "1. size: " << s.size() << std::endl;
		s.pop();
		std::cout << "2. size: " << s.size() << std::endl << "-------------------" << std::endl;
	}
	{
		std::cout << "> top" << std::endl;
		std::stack<int> s;
		s.push(10);
		s.push(20);
		s.top() -= 5;
		std::cout << "s.top() is now " << s.top() << std::endl << "-------------------" << std::endl;
	}
	{
		std::cout << "> push" << std::endl;
		std::stack<int> s;
		for (int i = 0; i < 5; ++i)
			s.push(i);
		std::cout << "Popping out elements...";
		while (!s.empty())
		{
			std::cout << ' ' << s.top();
			s.pop();
		}
		std::cout << std::endl << "-------------------" << std::endl;
	}
}