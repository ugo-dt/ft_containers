/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:45:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/19 11:01:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{

# ifndef nullptr
#  define nullptr NULL
# endif

inline
int _convert_to_integral(int x) {return x;}

/*
 * enable_if
 */

template <bool B, typename Tp = void>
struct enable_if {};

template <typename Tp>
struct enable_if<true, Tp>
{
	typedef Tp type;
};

/*
 * is_integral
 */

template <class Tp, Tp v>
struct integral_constant
{
	static const Tp value = v;
	typedef Tp                value_type;
	typedef integral_constant type;

	operator value_type() const
		{return value;}
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

/* is_integral is false except for the built-in integer types. */
template <class T> struct is_integral              : false_type {};

template <> struct is_integral<bool>               : true_type {};
template <> struct is_integral<char>               : true_type {};
template <> struct is_integral<unsigned char>      : true_type {};
template <> struct is_integral<signed char>        : true_type {};
template <> struct is_integral<wchar_t>            : true_type {};
template <> struct is_integral<short>              : true_type {};
template <> struct is_integral<unsigned short>     : true_type {};
template <> struct is_integral<int>                : true_type {};
template <> struct is_integral<unsigned int>       : true_type {};
template <> struct is_integral<long>               : true_type {};
template <> struct is_integral<unsigned long>      : true_type {};
template <> struct is_integral<long long>          : true_type {};
template <> struct is_integral<unsigned long long> : true_type {};

}  // ft

#endif // TYPE_TRAITS_HPP
