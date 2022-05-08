/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/08 18:37:54 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "vector.hpp"
# include <vector>
# include <iostream>
# include <memory>

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

void	tests_vector_constructors();
void	tests_vector_iterators();

#endif // TESTS_H
