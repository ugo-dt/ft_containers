/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:15:30 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/12 21:30:29 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_BINARY_FUNCTION_H
# define FUNCTIONAL_BINARY_FUNCTION_H

namespace ft
{

template <class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1   first_argument_type;
	typedef Arg2   second_argument_type;
	typedef Result result_type;
}; // binary_function

}  // ft

#endif // FUNCTIONAL_BINARY_FUNCTION_H
