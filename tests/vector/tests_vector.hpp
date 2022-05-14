/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:07:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/14 17:22:37 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_HPP
# define TESTS_VECTOR_HPP

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

/*
template <class Tp>
class Allocator : public std::allocator<Tp>
{
public:
	typedef Tp             value_type;
	typedef Tp*            pointer;
	typedef const Tp*      const_pointer;
	typedef Tp&            reference;
	typedef const Tp&      const_reference;
	typedef std::size_t    size_type;
	typedef std::ptrdiff_t difference_type;

	std::allocator<Tp> a;

	template <class Up>
	Allocator(const Allocator<Up>&) {}

	Allocator() {std::cout << "Using Allocator class" << std::endl;}

	pointer allocate( size_type n, const void * hint = 0)
	{
		std::cout << "- Allocator: allocating size of " << n << std::endl;
		return (a.allocate(n, hint));
	}

	void deallocate( Tp* p, std::size_t n )
	{
		std::cout << "- Allocator: deallocating size of " << n << std::endl;
		a.deallocate(p, n);
	}

	void construct( pointer p, const_reference val )
	{
		std::cout << "- Allocator: constructing value" << std::endl;
		a.construct(p, val);
	}

	size_type max_size() const throw() { return a.max_size(); }

	void destroy( pointer p )
	{
		std::cout << "- Allocator: destructing value" << std::endl;
		a.destroy(p);
	}
};
*/

template <class T, class Allocator>
void	print_vector(const NAMESPACE::vector<T, Allocator>& v, bool e = true)
{
	std::cout << "size:     " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	if (!e)
		return ;
	for (typename NAMESPACE::vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << "- " << *it << std::endl;
}

void	tests_vector_constructors();
void	tests_vector_iterators();
void	tests_vector_capacity();
void	tests_vector_elem_access();
void	tests_vector_modifiers();
void	tests_vector_allocator();
void	tests_vector_operators();

#endif // TESTS_VECTOR_HPP
