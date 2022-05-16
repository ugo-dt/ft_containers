/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/16 12:00:24 by ugdaniel         ###   ########.fr       */
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

template <class Key, class Tp>
struct _value_type
{
	typedef Key                               key_type;
	typedef Tp                                mapped_type;
	typedef pair<const key_type, mapped_type> value_type;

private:
	value_type _cc;

public:
	value_type& get_value()
		{return _cc;}
	const value_type& get_value() const
		{return _cc};

private:
	_value_type();
	_value_type(const _value_type&);
	_value_type& operator=(const _value_type&);
	~_value_type();
};

template <class Tp>
struct _extract_key_value_types;

template <class Key, class Tp>
struct _extract_key_value_types<_value_type<Key, Tp> >
{
	typedef const Ke  key_type;
	typedef Tp        mapped_type;
};

template <class TreeIterator>
class _map_iterator
{
private:
	typedef typename TreeIterator::NodeTypes      NodeTypes;
	typedef typename TreeIterator::pointer_traits pointer_traits;

	TreeIterator _i;

public:
	typedef bidirectional_iterator_tag iterator_category;

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
	typedef 

public:
	map()
	{}

//	~map() {}
}; // map

}  // ft

#endif // MAP_HPP