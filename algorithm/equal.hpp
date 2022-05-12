/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:06:30 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/12 18:34:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_EQUAL_HPP
# define ALGORITHM_EQUAL_HPP

# include "iterator.hpp"

namespace ft
{

template <class InputIterator1, class InputIrerator2>
bool
equal(InputIterator1 first1, InputIterator1 last1, InputIrerator2 first2)
{
	for (; first1 != last1; ++first1, ++first2)
		if (*first1 != *first2)
			return (false);
	return (true);
}

template <class InputIterator1, class InputIrerator2, class BinaryPredicate>
bool
equal(InputIterator1 first1, InputIterator1 last1,
	  InputIrerator2 first2, BinaryPredicate pred)
{
	for (; first1 != last1; ++first1, ++first2)
		if (!pred(*first1, *first2))
			return (false);
	return (true);
}

template <class Tp>
void
swap(Tp& a, Tp& b)
{
	Tp	c(a);

	a = b;
	b = c;
}

}  // ft

#endif // ALGORITHM_EQUAL_HPP
