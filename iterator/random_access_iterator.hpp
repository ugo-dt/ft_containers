/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:09:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/03 16:44:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

template <class Tp>
class random_access_iterator
	: public ft::iterator<ft::random_access_iterator_tag, Tp>
{
	public:
		typedef random_access_iterator<Tp>			iterator;
		typedef random_access_iterator<const Tp> const_iterator;
		typedef typename iterator::value_type		value_type;
		typedef typename iterator::pointer			pointer;
		typedef typename iterator::reference		reference;
		typedef typename iterator::difference_type	difference_type;

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
		bool      operator==(const iterator &rhs) const {return this->_ptr == rhs._ptr;}
		bool      operator!=(const iterator &rhs) const {return this->_ptr != rhs._ptr;}
		bool      operator<(const iterator &rhs)  const {return this->_ptr < rhs._ptr;}
		bool      operator>(const iterator &rhs)  const {return this->_ptr > rhs._ptr;}
		bool      operator<=(const iterator &rhs) const {return this->_ptr <= rhs._ptr;}
		bool      operator>=(const iterator &rhs) const {return this->_ptr >= rhs._ptr;}

		pointer   operator->() const {return this->_ptr;}

		iterator  operator+(const int &rhs)	{return iterator(this->_ptr + rhs);}
		iterator  operator-(const int &rhs) {return iterator(this->_ptr - rhs);}
		operator  const_iterator()      {return const_iterator(this->_ptr);}
		iterator  &operator=(const random_access_iterator &rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
		iterator  operator++(int)
		{
			iterator i(*this);
			this->_ptr++;
			return i;
		}
		iterator  operator--(int)
		{
			iterator i(*this);
			this->_ptr--;
			return i;
		}
		iterator& operator++()
		{
			this->_ptr++;
			return *this;
		}
		iterator& operator--()
		{
			this->_ptr--;
			return *this;
		}
		iterator& operator+=(const int &rhs)
		{
			this->_ptr += rhs;
			return *this;
		}
		iterator& operator-=(const int &rhs)
		{
			this->_ptr -= rhs;
			return *this;
		}

		reference operator*()          const {return *(this->_ptr);}
		reference operator[](const int &n) const {return this->_ptr[n];}


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

		difference_type	operator-(const random_access_iterator &b) const {return _ptr - b._ptr;}

}; // random_access_iterator

}  // ft

#endif // RANDOM_ACCESS_ITERATOR_HPP
