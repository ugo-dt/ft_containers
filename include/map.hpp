/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/18 22:20:50 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "_rb_tree.hpp"
# include "algorithm.hpp"
# include "functional.hpp"
# include "utility.hpp"
# include <memory>
# include <stdexcept>

namespace ft
{

template <class TreeIterator>
class _map_iterator
{
private:
public:
	_map_iterator();
	~_map_iterator();
};

class  _map_const_iterator
{
private:
public:
	_map_const_iterator();
	~_map_const_iterator();
};

template <class Key, class Tp, class Compare = less<Key>,
          class Allocator = std::allocator<pair<const Key, Tp> > >
class map
{
public:
	typedef Key                                    key_type;
	typedef Tp                                     mapped_type;
	typedef pair<const key_type, mapped_type>      value_type;
	typedef Compare                                keyCompare;
	typedef Allocator                              allocator_type;

	// Compares objects of type value_type.
	class valueCompare
		: public binary_function<value_type, value_type, bool>
	{
		friend class map<Key, Tp, Compare, Allocator>;
	protected:
		keyCompare comp;

		valueCompare(keyCompare c)
			: comp(c)
		{
		}

		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	}; // valueCompare

private:
	// This turns a red-black tree into a map.
	typedef typename
		Allocator::template rebind<value_type>::other   _alloc_type;

	typedef _rb_tree<key_type, value_type, _alloc_type> _base;

	// The tree structure.
	_base	_tree;

public:
	typedef typename _alloc_type::pointer         pointer;
	typedef typename _alloc_type::const_pointer   const_pointer;
	typedef typename _alloc_type::reference       reference;
	typedef typename _alloc_type::const_reference const_reference;
	typedef typename _base::size_type             size_type;
	typedef typename _base::difference_type       difference_type;
	typedef typename _base::iterator              iterator;
	typedef typename _base::const_iterator        const_iterator;
	typedef typename _base::reverse_iterator      reverse_iterator;
	typedef typename _base::reverse_iterator      const_reverse_iterator;

	map()
		: _tree()
	{
	}

	explicit
	map(const Compare& c, const Allocator& a = Allocator())
		: _tree(c, a)
	{
	}

	map(const map& x)
		: _tree(x._tree)
	{
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last)
		: _tree()
	{
		_tree.insert_unique(first, last);
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const Compare& c,const Allocator& a = Allocator())
		: _tree(c, a)
	{
		_tree.insert_unique(first, last);
	}

	map&
	operator=(const map& x)
	{
		_tree = x._tree;
		return *this;
	}

	allocator_type getAllocator() const {return _tree.getAllocator();}

	iterator       begin()       {return _tree.begin();}
	const_iterator begin() const {return _tree.begin();}
	iterator       end()         {return _tree.end();}
	const_iterator end()   const {return _tree.end();}

	reverse_iterator       rbegin()       {return _tree.rbegin();}
	const_reverse_iterator rbegin() const {return _tree.rbegin();}
	reverse_iterator       rend()         {return _tree.rend();}
	const_reverse_iterator rend()   const {return _tree.rend();}

	bool empty() const {return _tree.empty();}

	size_type size()     const {return _tree.size();}
	size_type max_size() const {return _tree.max_size();}

	mapped_type&
	operator[](const key_type& k)
	{
		iterator i = lower_bound(k);
		// i->first is greater than or equivalent to k:
		if (i == end() || key_comp()(k, (*i).first))
			i = insert(i, value_type(k, mapped_type()));
		return (*i).second;
	}

	mapped_type&
	at(const key_type& k)
	{
		iterator i = lower_bound(k);
		if (i == end() || key_comp()(k, (*i).first))
			std::__throw_out_of_range("map::at: key not found");
		return (*i).second;
	}

	const mapped_type&
	at(const Key& k) const
	{
		const_iterator i = lower_bound(k);
		if (i == end() || key_comp()(k, (*i).first))
			std::__throw_out_of_range("map::at: key not found");
		return (*i).second;
	}

	ft::pair<iterator, bool>
	insert(const value_type& x)
	{
		return _tree.insert_unique(x);
	}

	iterator
	insert(iterator position, const value_type& x)
	{
		return _tree.insert_unique(position, x);
	}

	template <class InputIterator>
	void
	insert(InputIterator first, InputIterator last)
	{
		return _tree.insert_unique(first, last);
	}

	void
	erase(iterator position)
	{
		_tree.erase(position);
	}

	size_type
	erase(const key_type& x)
	{
		return _tree.erase(x);
	}

	void
	erase(iterator first, iterator last)
	{
		_tree.erase(first, last);
	}

	void
	swap(map& x)
	{
		_tree.swap(x._tree);
	}

	void
	clear()
	{
		_tree.clear();
	}

	keyCompare
	key_comp() const
	{
		return _tree.key_comp();
	}
	
	valueCompare
	value_comp() const
	{
		return valueCompare(_tree.key_comp());
	}

	iterator
	find(const key_type& x)
	{
		return _tree.find(x);
	}

	const_iterator
	find(const key_type& x) const
	{
		return _tree.find(x);
	}

	size_type
	count(const key_type& x) const
	{
		return _tree.find(x) == _tree.end() ? 0 : 1;
	}

	iterator
	lower_bound(const key_type& x)
	{
		return _tree.lower_bound(x);
	}

	const_iterator
	lower_bound(const key_type& x) const
	{
		return _tree.lower_bound(x);
	}

	iterator
	upper_bound(const key_type& x)
	{
		return _tree.upper_bound(x);
	}

	const_iterator
	upper_bound(const key_type& x) const
	{
		return _tree.upper_bound(x);
	}

	ft::pair<iterator, iterator>
	equal_range(const key_type& x)
	{
		return _tree.equal_range(x);
	}

	ft::pair<const_iterator, const_iterator>
	equal_range(const key_type& x) const
	{
		return _tree.equal_range(x);
	}
}; // map

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator==(const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator< (const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator!=(const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return !(x == y);
}

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator>(const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return y < x;
}

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator>=(const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return !(x < y);
}

template <class Key, class Tp, class Compare, class Allocator>
inline
bool
operator<=(const map<Key, Tp, Compare, Allocator>& x,
           const map<Key, Tp, Compare, Allocator>& y)
{
	return !(y < x);
}

template <class Key, class Tp, class Compare, class Allocator>
inline
void
swap(map<Key, Tp, Compare, Allocator>& x,
     map<Key, Tp, Compare, Allocator>& y)
{
    x.swap(y);
}

}  // ft

#endif // MAP_HPP