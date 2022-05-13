/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:21:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/13 15:53:29 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "type_traits.hpp"
# include <cstddef>

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template <class Category, class Tp, class Distance = ptrdiff_t,
	class Pointer = Tp*, class Reference = Tp&>
struct iterator
{
	typedef Tp        value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::value_type        value_type;
	typedef typename Iterator::pointer           pointer;
	typedef typename Iterator::reference         reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template <class Tp>
struct iterator_traits<Tp*>
{
	typedef ptrdiff_t                               difference_type;
	typedef Tp                                      value_type;
	typedef Tp*                                     pointer;
	typedef Tp&                                     reference;
	typedef typename ft::random_access_iterator_tag iterator_category;
};

template <class Tp>
struct iterator_traits<const Tp*>
{
	typedef ptrdiff_t                               difference_type;
	typedef Tp                                      value_type;
	typedef const Tp*                               pointer;
	typedef const Tp&                               reference;
	typedef typename ft::random_access_iterator_tag iterator_category;
};

}  //ft

#endif // ITERATOR_TRAITS_HPP
