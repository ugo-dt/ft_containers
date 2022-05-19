/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:03:06 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/19 19:15:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_FUNCTION_HPP
# define FUNCTIONAL_FUNCTION_HPP

namespace ft
{

template <class Arg, class Result>
struct unary_function
{
	typedef Arg    argument_type;
	typedef Result result_type;
};

template <class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1   first_argument_type;
	typedef Arg2   second_argument_type;
	typedef Result result_type;
}; // binary_function

template <class Pair>
struct _Select1st : public unary_function<Pair, class Pair::first_type>
{
	typename Pair::first_type&
	operator()(Pair& x)
		{return x.first;}

	const typename Pair::first_type&
	operator()(Pair& x) const
		{return x.first;}
};

}  // ft

#endif // FUNCTIONAL_FUNCTION_HPP
