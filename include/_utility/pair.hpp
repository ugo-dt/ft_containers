/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:05:23 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/22 15:05:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_PAIR_HPP
# define UTILITY_PAIR_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair()
		: first(),
		  second()
	{
	}

	pair(const first_type& a, const second_type& b)
		: first(a),
		  second(b)
	{
	}

	template <class U1, class U2>
	pair(const pair<U1, U2>& p)
		: first(p.first),
		  second(p.second)
	{
	}

	pair&
	operator=(const pair& p)
	{
		first = p.first;
		second = p.second;
		return *this;
	}
};

template <class T1, class T2>
inline
bool
operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return x.first == y.first && x.second == y.second;
}

template <class T1, class T2>
inline
bool
operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(x == y);
}

template <class T1, class T2>
inline
bool
operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <class T1, class T2>
inline
bool
operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return y < x;
}

template <class T1, class T2>
inline
bool
operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(x < y);
}

template <class T1, class T2>
inline
bool
operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(y < x);
}

template <class T1, class T2>
inline
pair<T1,T2>
make_pair(T1 x, T2 y)
{
	return pair<T1, T2>(x, y);
}

}  // ft


#endif // UTILITY_PAIR_HPP
