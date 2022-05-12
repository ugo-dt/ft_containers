/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_n.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:53:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/12 21:29:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_FILL_N_HPP
# define ALGORITHM_FILL_N_HPP

# include "iterator/iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{

template <class OutputIterator, class Size, class Tp>
inline
OutputIterator
_fill_n(OutputIterator first, Size n, const Tp& x)
{
	for (; n > 0; ++first, (void)--n)
		*first = x;
	return first;
}

template <class OutputIterator, class Size, class Tp>
inline
OutputIterator
fill_n(OutputIterator first, Size n, const Tp& x)
{
	return ft::_fill_n(first, ft::_convert_to_integral(n), x);
}

}  // ft

#endif // ALGORITHM_FILL_N_HPP
