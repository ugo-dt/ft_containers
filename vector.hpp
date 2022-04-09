/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/09 21:01:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

# include "random_access_iterator.hpp"
# include "algorithm.hpp"
# include <memory>
# include <stdexcept>

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
		typedef typename allocator_type::size_type				size_type;

		/* A random access iterator to value_type */
		typedef ft::random_access_iterator<value_type>			iterator;

		/* A random access iterator to const value_type */
		typedef ft::random_access_iterator<const value_type>	const_iterator;

// TODO		typedef ft::reverse_iterator	<iterator>				reverse_iterator;
// TODO		typedef ft::reverse_iterator<const_itertor>				const_reverse_iterator;

	// Attributes
	private:
		allocator_type	_alloc;		// Object used to allocate storage
		pointer			_begin;		// Pointer to the first element of the array
		size_type		_capacity;	// Maximum size currently allocated
		size_type		_size;		// Number of elements

	// Constructors
	public:
		/** 
		 * @brief Empty container constructor (default constructor).
		 * Constructs an empty container, with no elements.
		 *
		 * @param alloc Allocator object. The container keeps and uses an internal copy of this allocator.
		 */
		explicit vector(const allocator_type& alloc = allocator_type()):
			_alloc(alloc), 
			_begin(nullptr),
			_capacity(0),
			_size(0)
		{
			this->_vallocate(this->_capacity);
		}

		/** 
		 * @brief Fill constructor. Constructs a container with n elements.
		 * Each element is a copy of val.
		 * 
		 * @param n Initial container size (i.e., the number of elements in the container at construction).
		 * @param val Value to fill the container with. Each of the n elements in the container will be
		 * initialized to a copy of this value.
		 * @param alloc Allocator object. The container keeps and uses an internal copy of this allocator.
		 */
		explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
				_alloc(alloc),
				_begin(nullptr),
				_capacity(n),
				_size(0)
		{
			this->_vallocate(this->_capacity);
			for (; this->_size < this->_capacity; this->_size++)
				this->_alloc.construct(this->_begin + this->_size, val);
		}

		/** Range constructor
		 * 
		 * @brief Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, 
		 * in the same order.
		 * 
		 * @param first,last Input iterators to the initial and final positions in a range.
		 * The range used is [first,last), which includes all the elements between first and last,
		 * including the element pointed by first but not the element pointed by last.
		 */
	//	template <class InputIterator>
	//	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())

		/** Copy constructor
		 * 
		 * @brief Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, 
		 * in the same order.
		 * 
		 * @param x Another vector object of the same type (with the same class template
		 * arguments T and Alloc), whose contents are either copied or acquired.
		 */
		vector(const vector& x):
			_alloc(x._alloc),
			_begin(nullptr),
			_capacity(x._capacity),
			_size(0)
		{
			if (!this->_capacity) return ;
			this->_vallocate(this->_capacity);
			for (; this->_size < x._size; this->_size++)
				this->_alloc.construct(this->_begin + this->_size, x._begin[this->_size]);
		}

	// Destructor
	public:
		~vector(void) {this->_vdeallocate();}

	// Private member functions
	private:
		// Allocate array with size n
		void	_vallocate(size_type n)
		{
			if (n > this->max_size())
				std::__throw_length_error("vector");
			this->_begin = this->_alloc.allocate(n);
		}

		// Clears all vector allocations
		void	_vdeallocate(void) {
			if (!this->_begin)
				return ;
			this->clear();
			this->_alloc.deallocate(this->_begin, this->_capacity);
			this->_begin = nullptr;
			this->_capacity = 0;
		}

		// Returns a pointer to a newly allocated copy of the array used by the current instance
		pointer	_copy_array(void) {
			pointer p;
			if (!this->_begin) return (nullptr);
			p = this->_alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(p, this->_begin[i]);
			return (p);
		}

		// Deallocate all vector allocations, then allocate new storage of size c
		void	_re_allocate(size_type c) {
			pointer	p;
			if (c < this->_size)
				this->_size = c;
			p = _copy_array();
			this->_vdeallocate();
			this->_begin = p;
			this->_capacity = c;
		}

	// Public member functions
	public:
		/**
		 * @brief Copies all the elements from x into the container
		 *
		 * @param x A vector object of the same type (i.e., with the same template parameters,
		 * T and Alloc).
		 */
		vector&	operator=(const vector& x)
		{
			this->clear();
			if (*this != x)
			{
				if (this->_capacity < x._size)
					this->_re_allocate(x._size);
				for (size_type i = 0; i < x._size; i++)
					this->_alloc.construct(&this->_begin[i], x._begin[i]);
				this->_size = x._size;
			}
			return (*this);
		}

//		template <class InputIterator>
//		void assign (InputIterator first, InputIterator last)

		void assign (size_type n, const value_type& val)
		{
			if (n > this->_capacity)
				this->_re_allocate(n);
			for (this->_size = 0; this->_size < n; this->_size++)
				this->_alloc.construct(this->_begin + this->_size, val);
		}

		allocator_type	get_allocator(void) const {return this->_alloc;}

		// Element access
// TODO		at
// TODO		operator[]
// TODO		front
// TODO		back
// TODO		data

		// Iterators
		/* Returns an iterator pointing to the first element in the vector. */
		iterator		begin(void)		  {return iterator(this->_begin);}
		const_iterator	begin(void) const {return const_iterator(this->_begin);}

		/**
		 * @brief Returns an iterator referring to the past-the-end element in the vector container.
		 * The past-the-end element is the theoretical element that would follow the last element in
		 * the vector. It does not point to any element, and thus shall not be dereferenced.
		 * If the container is empty, this function returns the same as vector::begin.
		 */
		iterator		end(void)		{return iterator(this->_begin + this->_size);}
		const_iterator	end(void) const {return const_iterator(this->_begin + this->_size);}

// TODO		iterator	rbegin(void) const {return reverse_iterator(this->end());}
// TODO		iterator	rend(void) const {return reverse_iterator(this->begin());}

		// Capacity
		size_type	size(void)		const {return (this->_size);};

		size_type	max_size(void)	const {return (this->_alloc.max_size());}

		/**
		 * @brief Resizes the container so that it contains n elements. If n is
		 * smaller than the current container size, the content is reduced to its
		 * first n elements, removing those beyond (and destroying them).
		 * 
		 * If n is greater than the current container size, the content is expanded
		 * by inserting at the end as many elements as needed to reach a size of n.
		 * If val is specified, the new elements are initialized as copies of val,
		 * otherwise, they are value-initialized.
		 * 
		 * If n is also greater than the current container capacity, an automatic
		 * reallocation of the allocated storage space takes place. Notice that
		 * this function changes the actual content of the container by inserting
		 * or erasing elements from it.
		 * 
		 * @param n New container size, expressed in number of elements.
		 * Member type size_type is an unsigned integral type.
		 * @param val Object whose content is copied to the added elements in case
		 * that n is greater than the current container size. If not specified, the
		 * default constructor is used instead. Member type value_type is the type
		 * of the elements in the container, defined in vector as an alias of the
		 * first template parameter (T).
		 */
		void resize(size_type n, value_type val = value_type())
		{
			if (this->_size > n)
				while (this->_size > n)
					this->_alloc.destroy(this->_begin + this->_size--);
			else if (this->_size < n)
			{
				if (n > this->_capacity)
					this->_re_allocate(n);
				while (this->_size < n)
					this->_alloc.construct(this->_begin + this->_size++, val);
			}
		}

		size_type	capacity(void)	const {return this->_capacity;}

		/**
		 * @brief Returns whether the vector is empty (i.e. whether its size is 0).
		 * This function does not modify the container in any way.
		 * To clear the content of a vector, see vector::clear.
		 * 
		 * @return true if the container size is 0.
		 */
		bool		empty(void)		const {return this->_size == 0;}

// TODO		void		reserve(size_type);

		// Modifiers
		/**
		 * @brief Removes all elements from the vector (which are destroyed),
		 * leaving the container with a size of 0.
		 */
		void	clear(void)
		{
			if (this->_size == 0 || !this->_begin)
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_begin + i);
			this->_size = 0;
		}

// TODO		insert
// TODO		erase
// TODO		push_back
// TODO		pop_back

		/**
		 * @brief Exchanges the content of the container by the content of x,
		 * which is another vector object of the same type. Sizes may differ.
		 * 
		 * @param v Another vector container of the same type (i.e., instantiated
		 * with the same template parameters, T and Alloc) whose content is
		 * swapped with that of this container.
		 */
		void	swap(vector& v)
		{
			ft::swap(this->_alloc, v._alloc);
			ft::swap(this->_begin, v._begin);
			ft::swap(this->_size, v._size);
			ft::swap(this->_capacity, v._capacity);
		}

}; // vector

// vector non member functions
template<class T, class Allocator>
inline
bool	operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	const typename vector<T, Allocator>::size_type	sz = x.size();
	return sz == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template<class T, class Allocator>
inline
bool	operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return !(x == y);
}

template<class T, class Allocator>
inline
bool	operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<class T, class Allocator>
inline
bool	operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return y < x;
}

template<class T, class Allocator>
inline
bool	operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return !(y < x);
}

template<class T, class Allocator>
inline
bool	operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return !(x < y);
}

/**
 * @brief The contents of container x are exchanged with those of y.
 * Both container objects must be of the same type (same template parameters),
 * although sizes may differ.
 * 
 * @param x,y vector containers of the same type (i.e., having both the same template parameters, T and Alloc).
 */
template<class T, class Allocator>
inline
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
{
	x.swap(y);
}

} // ft

#endif // VECTOR_HPP