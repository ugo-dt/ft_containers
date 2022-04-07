/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/07 15:15:15 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{

template<typename T, class Allocator = std::allocator<T> >
class Vector
{
	// Member types
	public:
		/* First template parameter T */
		typedef T												value_type;

		/* Second template parameter, defaults to std::allocator<T> */
		typedef Allocator										allocator_type;	

		/* T& */
		typedef typename allocator_type::reference				reference;

		/* const T& */
		typedef typename allocator_type::const_reference		const_reference;

		/* T* */
		typedef typename allocator_type::pointer				pointer;

		/* const T* */
		typedef typename allocator_type::const_pointer			const_pointer;

		/* A signed integral type, usually the same as ptrdiff_t */
		typedef typename allocator_type::difference_type		difference_type	;

		/* A unsigned integral type that can represent any non-negative value of difference_type,
		 * usually the sane as size_t */
		//typedef typename allocator_type::size_type				size_type;

		/* A random access iterator to value_type */
		//typedef ft::random_access_iterator<value_type>			iterator;

		/* A random access iterator to const value_type */
		//typedef ft::random_access_iterator<const value_type>	const_iterator;

		//typedef ft::reverse_iterator	<iterator>				reverse_iterator;
		//typedef ft::reverse_iterator<const_itertor>				const_reverse_iterator;

	// Attributes
	private:
		allocator_type	_alloc;
		pointer			_vector;

	// Constructors
	public:
		/** Empty container constructor (default constructor).
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc template class used to allocate storage
		 */
		Vector(const allocator_type& alloc = allocator_type()) {}
	
	// Destructors
	public:
		~Vector(void);

}; // Vector

} // ft

#endif // VECTOR_HPP