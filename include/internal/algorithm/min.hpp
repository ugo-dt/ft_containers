/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:01:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/23 14:54:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_MIN_HPP
# define ALGORITHM_MIN_HPP

# include "functional.hpp"

namespace ft
{

template <class Tp, class Compare>
inline const Tp&
min(const Tp& a, const Tp& b, Compare comp)
{
	return comp(b, a) ? b : a;
}

template <class Tp>
inline const Tp&
min(const Tp& a, const Tp& b)
{
	return ft::min(a, b, less<Tp>());
}

}  // ft

#endif // ALGORITHM_MIN_HPP
