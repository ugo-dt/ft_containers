/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/07 16:26:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{

template<typename T, class Allocator = std::allocator<T> >
class vector
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
		typedef typename allocator_type::size_type			size_type;

		/* A random access iterator to value_type */
//		typedef ft::random_access_iterator<value_type>		iterator;

		/* A random access iterator to const value_type */
//		typedef ft::random_access_iterator<const value_type>	const_iterator;

// TODO: reverse_iterator
//		typedef ft::reverse_iterator	<iterator>				reverse_iterator;
//		typedef ft::reverse_iterator<const_itertor>			const_reverse_iterator;

	// Attributes
	private:
		allocator_type	_alloc;		// Object used to allocate storage
		pointer			_vector;	// Pointer to the start of the array
		size_type		_size;		// Number of elements
		size_type		_capacity;	// Maximum size currently allocated

	// Constructors
	public:
		/** Empty container constructor (default constructor).
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc template class used to allocate storage
		 */
		explicit vector(const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0), _capacity(0)
		{
			this->_vector = this->_alloc.allocate(_capacity);
			return ;
		}
	
	// Destructors
	public:
		~vector(void)
		{
			// TODO: destroy all elements first
			// no iterators yet
			this->_alloc.deallocate(_vector, _capacity);
			return ;
		}

}; // vector

} // ft

#endif // VECTOR_HPP