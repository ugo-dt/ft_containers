/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:09:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 10:12:44 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"
#include <iostream>

namespace ft
{

template <class Tp>
class random_access_iterator
	: public ft::iterator<ft::random_access_iterator_tag, Tp>
{
	public:
		typedef random_access_iterator<Tp>          iterator;
		typedef random_access_iterator<const Tp>    const_iterator;
		typedef typename iterator::value_type       value_type;
		typedef typename iterator::pointer          pointer;
		typedef typename iterator::reference        reference;
		typedef typename iterator::difference_type  difference_type;

	private:
		pointer	_ptr;

	public:
		random_access_iterator()
			: _ptr(nullptr)
		{
		}

		random_access_iterator(pointer ptr)
			: _ptr(ptr)
		{
		}

		random_access_iterator(const random_access_iterator &src)
		{
			*this = src;
		}

		~random_access_iterator() {}

	public:
		pointer base() const {return _ptr;}

		bool operator==(const iterator &y) const;
		bool operator!=(const iterator &y) const;
		bool operator<=(const iterator &y) const;
		bool operator>=(const iterator &y) const;
		bool operator<(const iterator &y)  const;
		bool operator>(const iterator &y)  const;

		//pointer   operator->() const {return this->_ptr;}

		iterator  operator+(const int &y);
		iterator  operator-(const int &y);

		operator  const_iterator() {return const_iterator(this->_ptr);}

		iterator  &operator=(const random_access_iterator &y);
		iterator  operator++(int);
		iterator  operator--(int);
		iterator& operator++();
		iterator& operator--();
		iterator& operator+=(const int &y);
		iterator& operator-=(const int &y);

		reference operator*() const;
		reference operator[](const int &n) const;

		friend	random_access_iterator	operator+(const int &x, const random_access_iterator &y)
		{
			random_access_iterator	i(y);
			i += x;
			return (i);
		}

		friend	random_access_iterator	operator-(const int &x, const random_access_iterator &y)
		{
			random_access_iterator	i(y);
			i -= x;
			return (i);
		}

		difference_type	operator-(const random_access_iterator &b) const {return _ptr - b._ptr;}

}; // random_access_iterator

template <class Tp>
bool
random_access_iterator<Tp>::operator==(const iterator &y) const
{
	return this->_ptr == y._ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator!=(const iterator &y) const
{
	return !(this->_ptr == y._ptr);
}

template <class Tp>
bool
random_access_iterator<Tp>::operator<(const iterator &y) const
{
	return this->_ptr < y._ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator>(const iterator &y) const
{
	return y._ptr < this->_ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator<=(const iterator &y) const
{
	return !(this->_ptr > y._ptr);
}

template <class Tp>
bool
random_access_iterator<Tp>::operator>=(const iterator &y) const
{
	return !(this->_ptr < y._ptr);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator+(const int &y)
{
	return iterator(this->_ptr + y);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator-(const int &y) {return iterator(this->_ptr - y);}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator=(const random_access_iterator &y)
{
	this->_ptr = y._ptr;
	return (*this);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator++(int)
{
	iterator i(*this);
	this->_ptr++;
	return i;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator--(int)
{
	iterator i(*this);
	this->_ptr--;
	return i;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator++()
{
	this->_ptr++;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator--()
{
	this->_ptr--;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator+=(const int &y)
{
	this->_ptr += y;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator-=(const int &y)
{
	this->_ptr -= y;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::reference
random_access_iterator<Tp>::operator*() const
{
	return *(this->_ptr);
}

template <class Tp1, class Tp2>
bool
operator==(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return x.base() == y.base();
}

template <class Tp1, class Tp2>
bool
operator!=(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return !(x.base() == y.base());
}

template <class Tp1, class Tp2>
bool
operator<(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return x.base() < y.base();
}

template <class Tp1, class Tp2>
bool
operator>(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return y.base() < x.base();
}

template <class Tp1, class Tp2>
bool
operator<=(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return !(x.base() > y.base());
}

template <class Tp1, class Tp2>
bool
operator>=(const random_access_iterator<Tp1> &x, const random_access_iterator<Tp2> &y)
{
	return !(x.base() < y.base());
}

}  // ft

#endif // RANDOM_ACCESS_ITERATOR_HPP
