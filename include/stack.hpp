/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/27 11:53:40 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

template <class Tp, class Container = ft::vector<Tp> > class stack;

template <class Tp, class Container>
class stack
{
public:
	typedef Container                           container_type;
	typedef	typename container_type::value_type value_type;
	typedef typename container_type::size_type  size_type;

protected:
	container_type c;

public:
	explicit stack(const container_type& cntr = container_type())
		: c(cntr)
	{
	}

	bool empty()     const        {return c.empty();}
	size_type size() const        {return c.size();}
	value_type& top()             {return c.back();}
	const value_type& top() const {return c.back();}

	void push(const value_type& val) {c.push_back(val);}

	void pop() {c.pop_back();}

	template <class T, class C>
	friend
	bool
	operator==(const stack<T, C>& x, const stack<T, C>& y);

	template <class T, class C>
	friend
	bool
	operator< (const stack<T, C>& x, const stack<T, C>& y);	
}; // stack

template <class Tp, class Container>
inline bool
operator==(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return x.c == y.c;
}

template <class Tp, class Container>
inline bool
operator<(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return x.c < y.c;
}

template <class Tp, class Container>
inline bool
operator!=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return !(x == y);
}

template <class Tp, class Container>
inline bool
operator>(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return y < x;
}

template <class Tp, class Container>
inline bool
operator>=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return !(x < y);
}

template <class Tp, class Container>
inline bool
operator<=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
{
	return !(y < x);
}

}  // ft

#endif // STACK_HPP
