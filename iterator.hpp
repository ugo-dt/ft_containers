/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:10:06 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/10 18:52:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template <class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance 	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
}; // iterator

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
}; // iterator_traits;

template <class T>
struct iterator_traits<T*>
{
	typedef ptrdiff_t								difference_type;
	typedef T										value_type;
	typedef T*										pointer;
	typedef T&										reference;
	typedef typename ft::random_access_iterator_tag	iterator_category;
}; // iterator_traits<T*>;

template <class T>
struct iterator_traits<const T*>
{
	typedef ptrdiff_t								difference_type;
	typedef T										value_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef typename ft::random_access_iterator_tag	iterator_category;
}; // iterator_traits<const T*>

template <typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
{
	public:
		typedef random_access_iterator<T>			iterator;
		typedef random_access_iterator<const T>		const_iterator;
		typedef typename iterator::value_type		value_type;
		typedef typename iterator::pointer			pointer;
		typedef typename iterator::reference		reference;
		typedef typename iterator::difference_type	difference_type;

	private:
		pointer	_ptr;

	public:
		random_access_iterator(void): _ptr(nullptr) {}
		random_access_iterator(pointer ptr): _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &src) {*this = src;}
		~random_access_iterator(void) {}

	public:
		random_access_iterator	&operator=(const random_access_iterator &rhs) {
			this->_ptr = rhs._ptr;
			return (*this);
		}

		operator	const_iterator(void) {return const_iterator(this->_ptr);}

		bool		operator==(const iterator &rhs)	const {return this->_ptr == rhs._ptr;}
		bool		operator!=(const iterator &rhs)	const {return this->_ptr != rhs._ptr;}

		reference	operator*(void)		const {return *(this->_ptr);}
		pointer		operator->(void)	const {return this->_ptr;}

		iterator&	operator++(void) {this->_ptr++; return *this;}
		iterator&	operator--(void) {this->_ptr--; return *this;}
		iterator	operator++(int) {iterator i(*this); this->_ptr++; return i;}
		iterator	operator--(int) {iterator i(*this); this->_ptr--; return i;}

		iterator	operator+(const int &rhs) {return iterator(this->_ptr + rhs);}
		iterator	operator-(const int &rhs) {return iterator(this->_ptr - rhs);}

		friend	random_access_iterator	operator+(const int &lhs, const random_access_iterator &rhs)
		{
			random_access_iterator	i(rhs);
			i += lhs;
			return (i);
		}

		friend	random_access_iterator	operator-(const int &lhs, const random_access_iterator &rhs)
		{
			random_access_iterator	i(rhs);
			i -= lhs;
			return (i);
		}

		bool		operator<(const iterator &rhs)	const {return this->_ptr < rhs._ptr;}
		bool		operator>(const iterator &rhs)	const {return this->_ptr > rhs._ptr;}
		bool		operator<=(const iterator &rhs)	const {return this->_ptr <= rhs._ptr;}
		bool		operator>=(const iterator &rhs)	const {return this->_ptr >= rhs._ptr;}

		iterator&	operator+=(const int &rhs) {this->_ptr += rhs; return *this;}
		iterator&	operator-=(const int &rhs) {this->_ptr -= rhs; return *this;}

		reference	operator[](const int &n) const {return this->_ptr[n];}
}; // random_access_iterator

} // ft

#endif // ITERATOR_HPP
