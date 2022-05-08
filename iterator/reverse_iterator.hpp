/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:59 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/07 14:29:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

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

		explicit reverse_iterator(iterator_type x)
			: current(x)
		{
		}

		template <class U>
		reverse_iterator(const reverse_iterator<U>& u)
			: current(u.base())
		{
		}
		
		~reverse_iterator()
		{
		}

		iterator_type		base()       const {return this->current;}
		pointer				operator->() const {return *(this->current);}

		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp(*this);
			--this->current;
			return tmp;
		}
		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp(*this);
			++this->current;
			return tmp;
		}

		reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(this->current - n);}
		reverse_iterator  operator- (difference_type n) const {return reverse_iterator(this->current + n);}

		reverse_iterator& operator++()
		{
			--this->current;
			return *this;
		}
		reverse_iterator& operator--()
		{
			++this->current;
			return *this;
		}

		reverse_iterator& operator+=(difference_type n)
		{
			this->current -= n;
			return *this;
		}
		reverse_iterator& operator-=(difference_type n)
		{
			this->current += n;
			return *this;
		}

		reference operator[](difference_type n) const {return *(*this + n);}
		reference operator*() const
		{
			iterator_type tmp = this->current;
			return *--tmp;
		}
};

template <class Iter1, class Iter2>
inline
bool
operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() == y.base();
}

template <class Iter1, class Iter2>
inline
bool
operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() > y.base();
}

template <class Iter1, class Iter2>
inline
bool
operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() != y.base();
}

template <class Iter1, class Iter2>
inline
bool
operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() < y.base();
}

template <class Iter1, class Iter2>
inline
bool
operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() <= y.base();
}

template <class Iter1, class Iter2>
inline
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
inline
reverse_iterator<Iter>
operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
{
    return reverse_iterator<Iter>(x.base() - n);
}

}  // ft

#endif // REVERSE_ITERATOR_HPP
