/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:31:52 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/08 19:57:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{

template<typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
{
	// Member types
	public:
		typedef random_access_iterator<T>			iterator;
		typedef random_access_iterator<const T>		const_iterator;
		typedef typename iterator::value_type		value_type;
		typedef typename iterator::pointer			pointer;
		typedef typename iterator::reference		reference;
		typedef typename iterator::difference_type	difference_type;
	
	// Attributes
	private:
		pointer	_ptr;
	
	// Constructors
	public:
		random_access_iterator(void): _ptr(nullptr) {}
		random_access_iterator(pointer ptr): _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &src) {*this = src;}
	
	// Destructor
	public:
		~random_access_iterator(void) {}
	
	// Member functions
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

#endif // RANDOM_ACCESS_ITERATOR_HPP
