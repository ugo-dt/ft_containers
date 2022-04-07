/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/07 22:32:24 by ugdaniel         ###   ########.fr       */
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
		pointer			_begin;		// Pointer to the first element of the array
		pointer			_end;		// Pointer to the last element of the array
		size_type		_size;		// Number of elements
		size_type		_capacity;	// Maximum size currently allocated

	// Constructors
	public:
		/** 
		 * @brief Empty container constructor (default constructor).
		 * Constructs an empty container, with no elements.
		 *
		 * @param alloc Allocator object. The container keeps and uses an internal copy of this allocator.
		 */
		explicit vector(const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _begin(nullptr), _end(nullptr), _size(0), _capacity(0)
		{
			this->_begin = this->_alloc.allocate(this->_capacity);
			return ;
		}

		/** 
		 * @brief Fill constructor. Constructs a container with n elements.
		 * Each element is a copy of val.
		 * 
		 * @param n Initial container size (i.e., the number of elements in the container at construction).
		 * @param val Value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
		 * @param alloc Allocator object. The container keeps and uses an internal copy of this allocator.
		 */
// TODO		explicit vector (size_type n, const value_type& val = value_type(),
//			const allocator_type& alloc = allocator_type());				// instanciate with n elements initialized to value

		/** Range constructor
		 * 
		 * @brief Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, 
		 * in the same order.
		 * @param first, last Input iterators to the initial and final positions in a range. The range used is [first,last), which includes all the elements between first and last, including the element pointed by first but not the element pointed by last.
		 */
// TODO		template <class InputIterator>
//		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); 										// initialiaze with values of another with iterators

		/** Copy constructor
		 * 
		 * @brief Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, 
		 * in the same order.
		 * @param x Another vector object of the same type (with the same class template
		 * arguments T and Alloc), whose contents are either copied or acquired.
		 */
// TODO		vector (const vector& x);

	// Destructors
	public:
		~vector(void)
		{
// TODO		destroy all elements first
			this->_alloc.deallocate(this->_begin, this->_capacity);
			return ;
		}
	
	// Member functions
	public:
// TODO		operator=
// TODO		assign
// TODO		get_allocator

		/* Element access */
// TODO		at
// TODO		operator[]
// TODO		front
// TODO		back
// TODO		data

		/* Iterators */
// TODO		begin
// TODO		end
// TODO		rbegin
// TODO		rend

		/* Capacity */
		bool		empty(void)		const {return (this->_begin() == this->_end());}
		size_type	size(void)		const {return (this->_size);};
		size_type	max_size(void)	const {return (this->_alloc.max_size());}
// TODO		void		reserve(size_type);
		size_type	capacity(void)	const {return (this->_capacity);}

		/* Modifiers */
// TODO		clear
// TODO		insert
// TODO		erase
// TODO		push_back
// TODO		pop_back
// TODO		resize
// TODO		swap

}; // vector

/* vector non member functions */
// TODO		operator==
// TODO		operator!=
// TODO		operator<
// TODO		operator<=
// TODO		operator>
// TODO		operator>=
// TODO		template< class T, class Alloc > void swap(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs);

} // ft

#endif // VECTOR_HPP