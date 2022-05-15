/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:09:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/15 11:50:09 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_RANDOM_ACCESS_HPP
# define ITERATOR_RANDOM_ACCESS_HPP

# include "iterator_traits.hpp"

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

		random_access_iterator(const random_access_iterator& x)
			: _ptr(x._ptr)
		{
		}

	public:
		pointer base() const {return _ptr;}

		bool operator==(const iterator& y) const;
		bool operator!=(const iterator& y) const;
		bool operator<=(const iterator& y) const;
		bool operator>=(const iterator& y) const;
		bool operator<(const iterator& y)  const;
		bool operator>(const iterator& y)  const;

		pointer   operator->() const {return _ptr;}

		iterator  operator+(const int& y) const;
		iterator  operator-(const int& y) const;

		operator  const_iterator() {return const_iterator(_ptr);}

		iterator & operator=(const random_access_iterator& y);
		iterator  operator++(int);
		iterator  operator--(int);
		iterator& operator++();
		iterator& operator--();
		iterator& operator+=(const int& y);
		iterator& operator-=(const int& y);

		reference operator*() const;
		reference operator[](const int& n) const;

		friend	random_access_iterator	operator+(const int& x, const random_access_iterator& y)
		{
			random_access_iterator	i(y);
			i += x;
			return (i);
		}

		friend	random_access_iterator	operator-(const int& x, const random_access_iterator& y)
		{
			random_access_iterator	i(y);
			i -= x;
			return (i);
		}

		difference_type	operator-(const random_access_iterator& b) const {return _ptr - b._ptr;}

}; // random_access_iterator

template <class Tp>
bool
random_access_iterator<Tp>::operator==(const iterator& y) const
{
	return _ptr == y._ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator!=(const iterator& y) const
{
	return !(_ptr == y._ptr);
}

template <class Tp>
bool
random_access_iterator<Tp>::operator<(const iterator& y) const
{
	return _ptr < y._ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator>(const iterator& y) const
{
	return y._ptr < _ptr;
}

template <class Tp>
bool
random_access_iterator<Tp>::operator<=(const iterator& y) const
{
	return !(_ptr > y._ptr);
}

template <class Tp>
bool
random_access_iterator<Tp>::operator>=(const iterator& y) const
{
	return !(_ptr < y._ptr);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator+(const int& y) const
{
	return iterator(_ptr + y);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator-(const int& y) const
{
	return iterator(_ptr - y);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator=(const random_access_iterator& y)
{
	_ptr = y._ptr;
	return (*this);
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator++(int)
{
	iterator i(*this);
	_ptr++;
	return i;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator
random_access_iterator<Tp>::operator--(int)
{
	iterator i(*this);
	_ptr--;
	return i;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator++()
{
	_ptr++;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator--()
{
	_ptr--;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator+=(const int& y)
{
	_ptr += y;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::iterator&
random_access_iterator<Tp>::operator-=(const int& y)
{
	_ptr -= y;
	return *this;
}

template <class Tp>
typename random_access_iterator<Tp>::reference
random_access_iterator<Tp>::operator*() const
{
	return *_ptr;
}

template <class Tp>
typename random_access_iterator<Tp>::reference
random_access_iterator<Tp>::operator[](const int&n ) const
{
	return _ptr[n];
}

template <class Tp1, class Tp2>
bool
operator==(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return x.base() == y.base();
}

template <class Tp1, class Tp2>
bool
operator!=(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return !(x.base() == y.base());
}

template <class Tp1, class Tp2>
bool
operator<(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return x.base() < y.base();
}

template <class Tp1, class Tp2>
bool
operator>(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return y.base() < x.base();
}

template <class Tp1, class Tp2>
bool
operator<=(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return !(x.base() > y.base());
}

template <class Tp1, class Tp2>
bool
operator>=(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return !(x.base() < y.base());
}

template <class Tp1, class Tp2>
typename random_access_iterator<Tp1>::difference_type
operator-(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return x.base() - y.base();
}

template <class Tp1, class Tp2>
typename random_access_iterator<Tp1>::iterator
operator+(const random_access_iterator<Tp1>& x, const random_access_iterator<Tp2>& y)
{
	return x.base() + y.base();
}

}  // ft

#endif // ITERATOR_RANDOM_ACCESS_HPP
