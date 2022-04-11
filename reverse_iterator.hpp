/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:59 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/11 20:43:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{

template <class Iter>
class reverse_iterator
{
	// Member types
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;		
	
	protected:
		iterator_type	current;

	public:
		reverse_iterator(void) : current() {}

		explicit reverse_iterator(iterator_type x) : current(x) {}

		template <class U>
			reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {}
		
		~reverse_iterator(void) {}

		iterator_type		base(void) const {return this->current;}
		reference			operator*(void) const {iterator_type tmp = this->current; return *--tmp;}
		pointer				operator->(void) const {return *(this->current);}
		reverse_iterator&	operator++() {--this->current; return *this;}
		reverse_iterator	operator++(int) {reverse_iterator tmp(*this); --this->current; return tmp;}
		reverse_iterator&	operator--() {++this->current; return *this;}
		reverse_iterator	operator--(int) {reverse_iterator tmp(*this); ++this->current; return tmp;}
		reverse_iterator	operator+ (difference_type n) const {return reverse_iterator(this->current - n);}
		reverse_iterator&	operator+=(difference_type n) {this->current -= n; return *this;}
		reverse_iterator	operator- (difference_type n) const {return reverse_iterator(this->current + n);}
		reverse_iterator&	operator-=(difference_type n) {this->current += n; return *this;}
		reference			operator[](difference_type n) const {return *(*this + n);}
};

template <class _Iter1, class _Iter2>
inline
bool
operator!=(const reverse_iterator<_Iter1>& x, const reverse_iterator<_Iter2>& y)
{
    return x.base() != y.base();
}

}	// ft

#endif // REVERSE_ITERATOR_HPP
