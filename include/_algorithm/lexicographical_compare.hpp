/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:23:39 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/12 21:30:12 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP
# define ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

template <class InputIterator1, class InputIterator2>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (first2 == last2 || *first1 > *first2)
			return (false);
		else if (*first1 < *first2)
			return (true);
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2,
						Compare comp)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return (false);
		else if (comp(*first1, *first2))
			return (true);
	}
	return (first2 != last2);
}

};  // ft

#endif // ALGORITHM_LEXICOGRAPHICAL_COMPARE_HPP
