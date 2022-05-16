/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:28:34 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/16 11:18:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_OPERATIONS_HPP
# define FUNCTIONAL_OPERATIONS_HPP

namespace ft
{

template <class Tp>
struct less
{
	typedef Tp   first_argument_type;
	typedef Tp   second_argument_type;
	typedef bool result_type;

	bool operator()(const Tp& x, const Tp& y) const
		{return x < y;}
};

}  // ft

#endif // FUNCTIONAL_OPERATIONS_HPP
