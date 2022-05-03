/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:06:30 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/03 16:46:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include "iterator/iterator.hpp"

namespace ft
{

template <class InputIterator1, class InputIrerator2>
bool
equal(InputIterator1 first1, InputIterator1 last1, InputIrerator2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

template <class InputIterator1, class InputIrerator2, class BinaryPredicate>
bool
equal(InputIterator1 first1, InputIterator1 last1,
	  InputIrerator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

template <class InputIterator1, class InputIterator2>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first1 > *first2)
			return (false);
		else if (*first1 < *first2)
			return (true);
		first1++;
		first2++;
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2,
						Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return (false);
		else if (comp(*first1, *first2))
			return (true);
		first1++;
		first2++;
	}
	return (first2 != last2);
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

#endif // ALGORITHM_HPP
