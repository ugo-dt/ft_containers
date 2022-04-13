/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:09:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/13 09:41:03 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

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
		iterator	&operator=(const random_access_iterator &rhs) {this->_ptr = rhs._ptr; return (*this);}
		bool		operator==(const iterator &rhs) const {return this->_ptr == rhs._ptr;}
		bool		operator!=(const iterator &rhs) const {return this->_ptr != rhs._ptr;}
		bool		operator<(const iterator &rhs)	const {return this->_ptr < rhs._ptr;}
		bool		operator>(const iterator &rhs)	const {return this->_ptr > rhs._ptr;}
		bool		operator<=(const iterator &rhs)	const {return this->_ptr <= rhs._ptr;}
		bool		operator>=(const iterator &rhs)	const {return this->_ptr >= rhs._ptr;}
		reference	operator*(void) const {return *(this->_ptr);}
		pointer		operator->(void) const {return this->_ptr;}
		iterator&	operator++(void) {this->_ptr++; return *this;}
		iterator&	operator--(void) {this->_ptr--; return *this;}
		iterator	operator++(int) {iterator i(*this); this->_ptr++; return i;}
		iterator	operator--(int) {iterator i(*this); this->_ptr--; return i;}
		iterator	operator+(const int &rhs) {return iterator(this->_ptr + rhs);}
		iterator	operator-(const int &rhs) {return iterator(this->_ptr - rhs);}
		iterator&	operator+=(const int &rhs) {this->_ptr += rhs; return *this;}
		iterator&	operator-=(const int &rhs) {this->_ptr -= rhs; return *this;}
		reference	operator[](const int &n) const {return this->_ptr[n];}
		operator	const_iterator(void) {return const_iterator(this->_ptr);}

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

}; // random_access_iterator

}  // ft

#endif // RANDOM_ACCESS_ITERATOR_HPP
