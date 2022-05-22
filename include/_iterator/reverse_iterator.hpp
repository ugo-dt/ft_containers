/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:59 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/22 13:33:39 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_REVERSE_HPP
# define ITERATORS_REVERSE_HPP

# include "iterator_traits.hpp"

namespace ft
{

template <class Iter>
class reverse_iterator
{
	// Member types
	public:
		typedef Iter                                              iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename iterator_traits<Iter>::value_type        value_type;
		typedef typename iterator_traits<Iter>::difference_type   difference_type;
		typedef typename iterator_traits<Iter>::pointer           pointer;
		typedef typename iterator_traits<Iter>::reference         reference;		
	
	protected:
		iterator_type	current;

	public:
		reverse_iterator()
			: current()
		{
		}

		explicit
		reverse_iterator(iterator_type x)
			: current(x)
		{
		}

		template <class Iter2>
		reverse_iterator(const reverse_iterator<Iter2>& u)
			: current(u.base())
		{
		}

		template <class Iter2>
		reverse_iterator& operator=(const reverse_iterator<Iter2>& u)
		{
			current = u.base();
			return *this;
		}

		iterator_type     base() const
			{return current;}

		reference         operator*() const
		{
			Iter tmp = current;
			return *--tmp;
		}

		pointer           operator->() const
			{return &(operator*());}

		reverse_iterator& operator++()
		{
			--current;
			return *this;
		}

		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp(*this);
			--current;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++current;
			return *this;
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp(*this);
			++current;
			return tmp;
		}

		reverse_iterator  operator+ (difference_type __n) const
			{return reverse_iterator(current - __n);}
		reverse_iterator& operator+=(difference_type __n)
			{current -= __n; return *this;}
		reverse_iterator  operator- (difference_type __n) const
			{return reverse_iterator(current + __n);}
		reverse_iterator& operator-=(difference_type __n)
			{current += __n; return *this;}
		reference         operator[](difference_type __n) const
			{return *(*this + __n);}
};

template <class Iter1, class Iter2>
bool
operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() == y.base();
}

template <class Iter1, class Iter2>
bool
operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() > y.base();
}

template <class Iter1, class Iter2>
bool
operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() != y.base();
}

template <class Iter1, class Iter2>
bool
operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() < y.base();
}

template <class Iter1, class Iter2>
bool
operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() <= y.base();
}

template <class Iter1, class Iter2>
bool
operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() >= y.base();
}

template <class Iter1, class Iter2>
inline
typename reverse_iterator<Iter1>::difference_type
operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return y.base() - x.base();
}

template <class Iter>
reverse_iterator<Iter>
operator+(typename reverse_iterator<Iter>::difference_type __n, const reverse_iterator<Iter>& x)
{
    return reverse_iterator<Iter>(x.base() - __n);
}

}  // ft

#endif // ITERATORS_REVERSE_HPP
