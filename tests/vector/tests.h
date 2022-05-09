/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 10:54:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "vector.hpp"
# include <vector>
# include <iostream>
# include <memory>
# include <string>

#ifndef NAMESPACE
# ifdef STD
#  define NAMESPACE		std
# else
#  define NAMESPACE		ft
# endif
#endif

class Class
{
	private:
		int	_x;

	public:
		Class()
		{}

		Class(const Class &x)
			: _x(x._x)
		{}

		~Class()
		{}

		void x() {std::cout << this->_x << std::endl;}
}; // Class

template <class T>
void	print_vector(const NAMESPACE::vector<T>& v, bool e = true)
{
	std::cout << "size:     " << v.size() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	if (!e)
		return ;
	for (typename NAMESPACE::vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

void	tests_vector_constructors();
void	tests_vector_iterators();

#endif // TESTS_H
