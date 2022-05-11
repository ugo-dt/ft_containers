/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:31:44 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/11 21:03:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_vector.hpp"

void	tests_vector_allocator()
{
	std::cout << "> allocator" << std::endl;
	std::vector<int> v;
	int *p;
	unsigned int i;
	// allocate an array with space for 5 elements using vector's allocator:
	p = v.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		v.get_allocator().construct(&p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << std::endl;

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		v.get_allocator().destroy(&p[i]);
	v.get_allocator().deallocate(p,5);
	std::cout << "-------------------" << std::endl;
}
