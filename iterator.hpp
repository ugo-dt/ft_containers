/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:10:06 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/08 18:55:45 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct iterator
{
	/* Type of elements pointed by the iterator. */
	typedef T			value_type;

	/* Type to represent the difference between two iterators. */
	typedef Distance 	difference_type;

	/* Type to represent a pointer to an element pointed by the iterator. */
	typedef Pointer		pointer;

	/* Type to represent a reference to an element pointed by the iterator */
	typedef Reference	reference;

	/** Category to which the iterator belongs to. It must be one of the following iterator tags
	 * 
	 * input_iterator_tag: Input Iterator
	 * output_iterator_tag: Output Iterator
	 * forward_iterator_tag: Forward Iterator
	 * bidirectional_iterator_tag: Bidirectional Iterator
	 * random_access_iterator_tag: Random-access Iterator
	 */
	typedef Category	iterator_category;
};
} // ft

#endif // ITERATOR_HPP
