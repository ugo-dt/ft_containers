/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:09:15 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/20 17:12:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_DISTANCE_HPP
# define ITERATOR_DISTANCE_HPP

# include "iterator_traits.hpp"

namespace ft
{

template <class InputIter>
inline
typename iterator_traits<InputIter>::difference_type
_distance(InputIter first, InputIter last, input_iterator_tag)
{
    typename iterator_traits<InputIter>::difference_type r(0);
    for (; first != last; ++first)
        ++r;
    return r;
}

template <class RandIter>
inline
typename iterator_traits<RandIter>::difference_type
_distance(RandIter first, RandIter last, random_access_iterator_tag)
{
    return last - first;
}

template <class InputIter>
inline
typename iterator_traits<InputIter>::difference_type
distance(InputIter first, InputIter last)
{
    return ft::_distance(first, last, typename iterator_traits<InputIter>::iterator_category());
}

}  // ft

#endif // ITERATOR_DISTANCE_HPP
