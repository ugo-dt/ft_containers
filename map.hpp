/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/14 17:39:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "_tree.hpp"
# include "functional.hpp"
# include "utility.hpp" // std::pair
# include <memory> // std::allocator

namespace ft
{

class _map_iterator
{
	_map_iterator();
	~_map_iterator();
};

class  _map_const_iterator
{
	_map_const_iterator();
	~_map_const_iterator();
};

template <class Key, class Tp, class Compare = less<Key>,
          class Allocator = std::allocator<pair<const Key, Tp> > >
class map
{
public:
	typedef Key                                      key_type;
	typedef Tp                                       mapped_type;
	typedef pair<const key_type, mapped_type>        value_type;
	typedef Compare                                  key_compare;
	typedef Allocator                                allocator_type;
	typedef typename allocator_type::reference       reference;
	typedef typename allocator_type::const_reference const_reference;

	class value_comp
		: public binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		key_compare comp;

		value_comp(key_compare c) : comp(c) {}

		bool operator()(const value_type& x, const value_type& y) const
			{return comp(x.first, y.first);}
	};

private:
	//typedef _tree<

public:
	map()
	{}

//	~map() {}
}; // map

}  // ft

#endif // MAP_HPP
