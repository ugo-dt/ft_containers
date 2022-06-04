/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:51:04 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/23 14:53:44 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_MAX_HPP
# define ALGORITHM_MAX_HPP

namespace ft
{

template <class Tp, class Compare>
inline const Tp &
max(const Tp &a, const Tp &b, Compare comp)
{
	return comp(a, b) ? b : a;
}

template <class Tp>
inline const Tp &
max(const Tp &a, const Tp &b)
{
	return a < b ? b : a;
}

}  // ft

#endif // ALGORITHM_MAX_HPP
