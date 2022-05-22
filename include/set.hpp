/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:15:39 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/22 19:13:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "_rb_tree.hpp"
# include "functional.hpp"
# include <memory>

namespace ft
{

template <class Key, class Compare = less<Key>,
          class Allocator = std::allocator<Key> >
class set
{
public:
	typedef Key       key_type;
	typedef Key       value_type;
	typedef Compare   key_compare;
	typedef Compare   value_compare;
	typedef Allocator allocator_type;

private:
	typedef typename
		Allocator::template rebind<Key>::other _key_alloc_type;

	typedef _rb_tree<key_type, value_type, _identity<value_type>,
		key_compare, _key_alloc_type> _base;
	
	// The tree structure, representing a set.
	_base _tree;

public:
	typedef typename _key_alloc_type::pointer         pointer;
	typedef typename _key_alloc_type::const_pointer   const_pointer;
	typedef typename _key_alloc_type::reference       reference;
	typedef typename _key_alloc_type::const_reference const_reference;
	typedef typename _base::const_iterator            iterator;
	typedef typename _base::const_iterator            const_iterator;
	typedef typename _base::const_reverse_iterator    reverse_iterator;
	typedef typename _base::const_reverse_iterator    const_reverse_iterator;
	typedef typename _base::size_type                 size_type;
	typedef typename _base::difference_type           difference_type;

	set()
		: _tree()
	{
	}

	explicit
	set(const Compare& c, const allocator_type& a = allocator_type())
		: _tree(c, a)
	{
	}

	template <class InputIterator>
	set(InputIterator first, InputIterator last)
		: _tree()
	{
		_tree._insert_unique(first, last);
	}

	template <class InputIterator>
	set(InputIterator first, InputIterator last,
	    const Compare& c, const allocator_type& a = allocator_type())
		: _tree(c, a)
	{
		_tree._insert_unique(first, last);
	}

	set(const set& x)
		: _tree(x._tree)
	{
	}

	set&
	operator=(const set& x)
	{
		this->_tree = x._tree;
		return *this;
	}

	key_compare key_comp() const
		{return _tree.key_comp();}
	
	value_compare value_comp() const
		{return _tree.key_comp();}
	
	allocator_type get_allocator() const
		{return _tree.get_allocator();}

	iterator         begin()  const {return _tree.begin();}
	iterator         end()    const {return _tree.end();}
	reverse_iterator rbegin() const {return _tree.rbegin();}
	reverse_iterator rend()   const {return _tree.rend();}

	bool empty() const
		{return _tree.empty();}

	size_type size() const
	{return _tree.size();}

	size_type max_size() const
		{return _tree.max_size();}

	void swap(set& x)
		{_tree.swap(x._tree);}

	pair<iterator, bool> insert(const value_type& x)
	{
		pair<typename _base::iterator, bool> p = _tree._insert_unique(x);
		return pair<iterator, bool>(p.first, p.second);
	}

	iterator insert(const_iterator position, const value_type& x)
		{return _tree._insert_unique(position, x);}

	template<typename _InputIterator>
	void insert(_InputIterator first, _InputIterator last)
		{_tree._insert_unique(first, last);}

	void erase(iterator position)
		{_tree.erase(position);}

	size_type erase(const key_type& x)
		{return _tree.erase(x);}

	void erase(iterator first, iterator last)
		{_tree.erase(first, last);}

	void clear()
		{_tree.clear();}

	size_type      count(const key_type& x) const
		{return _tree.find(x) == _tree.end() ? 0 : 1;}

	iterator       find(const key_type& x)
		{return _tree.find(x);}

	const_iterator find(const key_type& x) const
		{return _tree.find(x);}

	iterator       lower_bound(const key_type& x)
		{return _tree.lower_bound(x);}

	const_iterator lower_bound(const key_type& x) const
		{return _tree.lower_bound(x);}

	iterator       upper_bound(const key_type& x)
		{return _tree.upper_bound(x);}

	const_iterator upper_bound(const key_type& x) const
		{return _tree.upper_bound(x);}

	pair<iterator, iterator> equal_range(const key_type& x)
		{return _tree.equal_range(x);}

	pair<const_iterator, const_iterator> equal_range(const key_type& x) const
		{return _tree.equal_range(x);}

	template<typename K, typename C, typename A>
	friend bool
	operator==(const set<K, C, A>&, const set<K, C, A>&);

	template<typename K, typename C, typename A>
	friend bool
	operator<(const set<K, C, A>&, const set<K, C, A>&);
};

template<typename Key, typename Compare, typename Alloc>
inline bool
operator==(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return x._tree == y._tree;
}

template<typename Key, typename Compare, typename Alloc>
inline bool
operator<(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return x._tree < y._tree;
}

template<typename Key, typename Compare, typename Alloc>
inline bool
operator!=(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return !(x == y);
}

template<typename Key, typename Compare, typename Alloc>
inline bool
operator>(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return y < x;
}

template<typename Key, typename Compare, typename Alloc>
inline bool
operator<=(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return !(y < x);
}

template<typename Key, typename Compare, typename Alloc>
inline bool
operator>=(const set<Key, Compare, Alloc>& x,
const set<Key, Compare, Alloc>& y)
{
	return !(x < y);
}

template<typename Key, typename Compare, typename Alloc>
inline void
swap(set<Key, Compare, Alloc>& x, set<Key, Compare, Alloc>& y)
{
	x.swap(y);
}

}  // ft

#endif // SET_HPP
