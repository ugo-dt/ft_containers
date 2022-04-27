/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/27 19:06:47 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "algorithm.hpp"
# include "iterator/iterator.hpp"
# include <stdexcept>

namespace ft
{

/*  class vector synopsis  */
template <typename T, class Allocator = std::allocator<T> >
class vector
{
	// Member types
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;	
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::difference_type		difference_type	;
		typedef typename allocator_type::size_type				size_type;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	// Attributes
	private:
		allocator_type			_alloc;		// Object used to allocate storage
		pointer					_begin;		// Pointer to the first element of the array
		size_type				_capacity;	// Maximum size currently allocated
		size_type				_size;		// Number of elements

	// Private member functions
	private:
		void					_vallocate(size_type n);
		void					_vdeallocate(void);
		void					_vreallocate(size_type c);
		void					_vconstruct(size_type pos, const value_type& val = value_type());
		void					_vconstruct(size_type start, size_type end, const value_type& val = value_type());
		void					_vconstruct(size_type start, size_type end, pointer x);
		pointer					_copy_array(void);
		iterator				_make_iter(pointer pos);
		const_iterator			_make_iter(pointer pos) const;
		reference				_make_ref(size_type pos);
		const_reference			_make_ref(size_type pos) const ;
		void					_throw_length_error(void) const;
		void					_throw_out_of_range(void) const;

	// Member functions
	public:
		explicit
		vector(const allocator_type& alloc = allocator_type());

		explicit
		vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type& alloc = allocator_type());

		vector(const vector& x);

		vector&	operator=(const vector& x);

		~vector(void)
			{this->_vdeallocate();}

		// Iterators
		iterator				begin(void);
		const_iterator			begin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		// Capacity
		size_type				size(void) const;
		size_type				max_size(void) const;
		void					resize(size_type n, value_type val = value_type());
		size_type				capacity() const;
		bool					empty() const;
		void					reserve(size_type n);

		// Element access
		reference				operator[] (size_type n);
		const_reference			operator[] (size_type n) const;
		reference				at(size_type n);
		const_reference			at(size_type n) const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

	// Modifiers
		template <class InputIterator>
			void				assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);
// TODO		void	push_back(const value_type& val);
// TODO		void	pop_back();
// TODO		iterator insert(iterator position, const value_type& val);
// TODO    		void insert(iterator position, size_type n, const value_type& val);
// TODO		template <class InputIterator>
// TODO		void insert(iterator position, InputIterator first, InputIterator last);
// TODO		iterator erase(iterator position);
// TODO		iterator erase(iterator first, iterator last);
		void					swap(vector& v);
		void					clear(void);

		allocator_type			get_allocator(void) const {return this->_alloc;}
};	// vector

// 

/** 
 * @brief Empty container constructor (default constructor).
 * Constructs an empty container, with no elements.
 *
 * @param alloc Allocator object. The container keeps and uses an internal copy of this allocator.
 */
template <typename T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& alloc) :
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
template <typename T, class Allocator>
vector<T, Allocator>::vector(size_type n, const value_type& val, const allocator_type& alloc) :
	_alloc(alloc),
	_begin(nullptr),
	_capacity(n),
	_size(n)
{
	this->_vallocate(this->_capacity);
	this->_vconstruct(0, n, val);
}

/** Range constructor
 * 
 * @brief Constructs a container with as many elements as the range [first,last),
 * with each element constructed from its corresponding element in that range, 
 * in the same order.
 * 
 * @param first,last Input iterators to the initial and final positions in a range.
 * The range used is (first,last), which includes all the elements between first and last,
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
template <typename T, class Allocator>
vector<T, Allocator>::vector(const vector& x) :
	_alloc(x._alloc),
	_begin(nullptr),
	_capacity(x._capacity),
	_size(x._size)
{
	if (!this->_capacity)
		return ;
	this->_vallocate(this->_capacity);
	this->_vconstruct(0, x._size, x._begin);
}

// Private member functions

// Allocate array with size n
template <typename T, class Allocator>
void
vector<T, Allocator>::_vallocate(size_type n)
{
	if (n > this->max_size())
		this->_throw_length_error();
	this->_begin = this->_alloc.allocate(n);
}

// Clears all vector allocations
template <typename T, class Allocator>
void
vector<T, Allocator>::_vdeallocate(void)
{
	if (!this->_begin)
		return ;
	this->clear();
	this->_alloc.deallocate(this->_begin, this->_capacity);
	this->_begin = nullptr;
	this->_capacity = 0;
}

// Deallocate all vector allocations, then allocate new storage of size c
template <typename T, class Allocator>
void
vector<T, Allocator>::_vreallocate(size_type c)
{
	vector	v(c);

	if (c < this->_size)
		this->_size = c;
	v._vconstruct(0, this->_size, this->_begin);
	v._size = this->_size;
	swap(v);
}

/* Construct object at position pos in array, with value val */
template <typename T, class Allocator>
inline
void
vector<T, Allocator>::_vconstruct(size_type pos, const value_type& val)
{
	this->_alloc.construct(this->_begin + pos, val);
}

/* Construct from start to end, not including end, with value val */
template <typename T, class Allocator>
inline
void
vector<T, Allocator>::_vconstruct(size_type start, size_type end, const value_type& val)
{
	for (size_type i = start; i < end; i++)
		this->_alloc.construct(this->_begin + i, val);
}

/* Copy array x, constructing from start to end */
template <typename T, class Allocator>
inline
void
vector<T, Allocator>::_vconstruct(size_type start, size_type end, pointer x)
{
	for (size_type i = start; i < end; i++)
		this->_alloc.construct(this->_begin + i, x[i]);
}

/* Returns an iterator to the element p */
template <typename T, class Allocator>
inline
typename ft::vector<T, Allocator>::iterator
vector<T, Allocator>::_make_iter(pointer p)
{
	return iterator(p);
}

/* Returns an constant iterator to the element p */
template <typename T, class Allocator>
inline
typename ft::vector<T, Allocator>::const_iterator
vector<T, Allocator>::_make_iter(pointer p) const
{
	return const_iterator(p);
}

/* Returns a reference to the element at the position pos */
template <typename T, class Allocator>
inline
typename ft::vector<T, Allocator>::reference
vector<T, Allocator>::_make_ref(size_type pos)
{
	return reference(*(_begin + pos));
}

/* Returns a constant reference to the element at the position pos */
template <typename T, class Allocator>
inline
typename ft::vector<T, Allocator>::const_reference
vector<T, Allocator>::_make_ref(size_type pos) const
{
	return reference(*(_begin + pos));
}

template <typename T, class Allocator>
void
vector<T, Allocator>::_throw_length_error(void) const
{
	std::__throw_length_error("vector");
}

template <typename T, class Allocator>
void
vector<T, Allocator>::_throw_out_of_range(void) const
{
	std::__throw_out_of_range("vector");
}

// Public member functions

/**
 * @brief Copies all the elements from x into the container
 *
 * @param x A vector object of the same type (i.e., with the same template parameters,
 * T and Alloc).
 */
template <class T, class Allocator>
typename ft::vector<T, Allocator>&
vector<T, Allocator>::operator=(const vector& x)
{
	this->clear();
	if (*this != x)
	{
		if (this->_capacity < x._size)
			this->_vreallocate(x._size);
		this->_vconstruct(0, x._size, x._begin);
		this->_size = x._size;
	}
	return (*this);
}

/* Returns an iterator pointing to the first element in the vector. */
template <typename T, class Allocator>
typename ft::vector<T, Allocator>::iterator
vector<T, Allocator>::begin(void)
{
	return _make_iter(this->_begin);
}

/* Returns a constant iterator pointing to the first element in the vector. */
template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin(void) const
{
	return _make_iter(this->_begin);
}

/**
 * @brief Returns an iterator referring to the past-the-end element in the vector container.
 * The past-the-end element is the theoretical element that would follow the last element in
 * the vector. It does not point to any element, and thus shall not be dereferenced.
 * If the container is empty, this function returns the same as vector::begin.
 */
template <typename T, class Allocator>
typename ft::vector<T, Allocator>::iterator
vector<T, Allocator>::end(void)
{
	return _make_iter(this->_begin + this->_size);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator
vector<T, Allocator>::end(void) const
{
	return _make_iter(this->_begin + this->_size);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin(void)
{
	return reverse_iterator(this->end());
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin(void) const
{
	return const_reverse_iterator(this->end());
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend(void)
{
	return reverse_iterator(this->begin());
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend(void) const
{
	return const_reverse_iterator(this->begin());
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::size_type
vector<T, Allocator>::size(void) const
{
	return this->_size;
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::size_type
vector<T, Allocator>::max_size(void) const
{
	return this->_alloc.max_size();
}

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
template <typename T, class Allocator>
void
vector<T, Allocator>::resize(size_type n, value_type val)
{
	if (this->_size > n)
		while (this->_size > n)
			this->_alloc.destroy(this->_begin + this->_size--);
	else if (this->_size < n)
	{
		if (n > this->_capacity)
			this->_vreallocate(n);
		this->_vconstruct(0, n, val);
		this->_size = n;
	}
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::size_type
vector<T, Allocator>::capacity(void) const
{
	return this->_capacity;
}

/**
 * @brief Returns whether the vector is empty (i.e. whether its size is 0).
 * This function does not modify the container in any way.
 * To clear the content of a vector, see vector::clear.
 * 
 * @return true if the container size is 0.
 */
template <typename T, class Allocator>
bool
vector<T, Allocator>::empty(void) const
{
	return this->_size == 0;
}

template <typename T, class Allocator>
void
vector<T, Allocator>::reserve(size_type n)
{
	if (n > this->_capacity)
		this->_vreallocate(n);
}

template <typename T, class Allocator>
template <class InputIterator>
void
vector<T, Allocator>::assign(InputIterator first, InputIterator last)
{
	this->clear();
	*this = vector(first, last);
}

template <typename T, class Allocator>
void
vector<T, Allocator>::assign(size_type n, const value_type& val)
{
	if (n > this->_capacity)
		this->_vreallocate(n);
	this->_vconstruct(0, n, val);
	this->_size = n;
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type n)
{
	return _make_ref(n);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type n) const
{
	return _make_ref(n);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reference
vector<T, Allocator>::at(size_type n)
{
	if (n >= this->_size)
		this->_throw_out_of_range();
	return (this->_begin[n]);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const
{
	if (n >= this->_size)
		this->_throw_out_of_range();
	return (this->_begin[n]);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reference
vector<T, Allocator>::front()
{
	return _make_ref(0);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const
{
	return _make_ref(0);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::reference
vector<T, Allocator>::back()
{
	return _make_ref(this->_size + 1);
}

template <typename T, class Allocator>
typename ft::vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const
{
	return _make_ref(this->_size + 1);
}

/**
 * @brief Removes all elements from the vector (which are destroyed),
 * leaving the container with a size of 0.
 */
template <typename T, class Allocator>
void
vector<T, Allocator>::clear(void)
{
	if (this->_size == 0 || !this->_begin)
		return ;
	for (size_type i = 0; i < this->_size; i++)
		this->_alloc.destroy(this->_begin + i);
	this->_size = 0;
}

/**
 * @brief Exchanges the content of the container by the content of x,
 * which is another vector object of the same type. Sizes may differ.
 * 
 * @param v Another vector container of the same type (i.e., instantiated
 * with the same template parameters, T and Alloc) whose content is
 * swapped with that of this container.
 */
template <typename T, class Allocator>
void
vector<T, Allocator>::swap(vector& v)
{
	ft::swap(this->_alloc, v._alloc);
	ft::swap(this->_begin, v._begin);
	ft::swap(this->_size, v._size);
	ft::swap(this->_capacity, v._capacity);
}

// vector non member functions
template <class T, class Allocator>
inline
bool
operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	const typename vector<T, Allocator>::size_type	sz = x.size();
	return sz == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class T, class Allocator>
inline
bool
operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return !(x == y);
}

template <class T, class Allocator>
inline
bool
operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T, class Allocator>
inline
bool
operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return y < x;
}

template <class T, class Allocator>
inline
bool
operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
{
	return !(y < x);
}

template <class T, class Allocator>
inline
bool
operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
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
template <class T, class Allocator>
inline
void
swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
{
	x.swap(y);
}

} // ft

#endif // VECTOR_HPP