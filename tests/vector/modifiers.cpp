/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/10 22:24:59 by ugdaniel         ###   ########.fr       */
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
		std::vector<int> myvector(3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert(it, 200);

		myvector.insert(it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = {501,502,503};
		myvector.insert (myvector.begin(), myarray, myarray + 3);

		std::cout << "myvector contains:";
		for (it = myvector.begin(); it != myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
}
