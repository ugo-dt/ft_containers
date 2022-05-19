/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rb_tree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:27:40 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/17 11:28:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

/** 
 * This is an internal header file, included by other library headers.
 * Do not use it directly.
 */

# include "functional.hpp"
# include "utility.hpp"
# include <memory>

namespace ft
{

enum _rb_tree_color {_node_red = false, _node_black = true};

struct _rb_tree_node_base
{
};

template <class Val>
struct _rb_tree_node
	: public _rb_tree_node_base
{
};

template <class Tp>
struct _rb_tree_iterator
{
};

template <class Tp>
struct _rb_tree_const_iterator
{
};

template <class Key, class Val, class KeyOfValue,
          class Compare, class Allocator = std::allocator<Val> >
class _rb_tree
{
private:
	typedef typename
		Allocator::template rebind<_rb_tree_node<Val> >::other _node_allocator;

protected:
	typedef _rb_tree_node_base*       _base_ptr;
	typedef const _rb_tree_node_base* _const_base_ptr;

public:
	typedef Key                       key_type;
	typedef Val                       value_type;
	typedef value_type*               pointer;
	typedef const value_type*         const_pointer;
	typedef value_type&               reference;
	typedef const value_type&         const_reference;
	typedef _rb_tree_node<Val>*       _link_type;
	typedef const _rb_tree_node<Val>* _const_link_type;
	typedef std::size_t               size_type;
	typedef std::ptrdiff_t            difference_type;
	typedef Allocator                 allocator_type;

	_node_allocator&
	_get_node_allocator()
	{
		return *static_cast<_node_allocator*>(&this->_tree);
	}

	const _node_allocator&
	_get_node_allocator() const
	{
		return *static_cast<_node_allocator*>(&this->_tree);
	}

	allocator_type
	get_allocator() const
	{
		return allocator_type(_get_node_allocator());
	}

protected:
	_link_type
	_get_node()
	{
		return _tree._node_allocator::allocate(1);
	}

	void
	_put_node(_link_type p)
	{
		_tree._node_allocator::deallocate(p, 1);
	}

	_link_type
	_create_node(const value_type& x)
	{
		_link_type tmp = _get_node();
		try
		{
			get_allocator().construct(&(tmp->_value_field), x);
		}
		catch (...)
		{
			_put_node(tmp);
			throw;
		}
		return tmp;
	}

	void
	_destroy_node(_link_type p)
	{
		get_allocator().destroy(&(p->_value_field));
		_put_node(p);
	}

	_link_type
	clone_node(_const_link_type x)
	{
		_link_type tmp = _create_node(x->_value_field);
		tmp->_color = x->_color;
		tmp->_left = 0;
		tmp->_right = 0;
		return tmp;
	}

protected:
	template <class Key_compare>
	struct _rb_tree_impl
		: public _node_allocator
	{
		Key_compare        _key_compare;
		_rb_tree_node_base _header;
		size_type          _node_count;

		_rb_tree_impl()
			: _node_allocator(),
			  _key_compare(),
			  _header(),
			  _node_count(0)
		{
			_initialize();
		}

		_rb_tree_impl(const Key_compare& c, const _node_allocator& a)
			: _node_allocator(a),
			  _key_compare(c),
			  _header(),
			  _node_count(0)
		{
			_initialize();
		}

	private:
		void
		_initialize()
		{
			this->_header._color = _node_red;
			this->_header._parent = 0;
			this->_header._left = &this->_header;
			this->_header._right = &this->_header;
		}
	}; // _rb_tree_impl

	_rb_tree_impl<Compare>	_tree;

protected:
	_base_ptr&       _root()
		{return this->_tree._header._parent;}
	_const_base_ptr  _root()      const
		{return this->_tree._header._parent;}
	_base_ptr&       _leftmost()
		{return this->_tree._header._left;}
	_const_base_ptr  _leftmost()  const
		{return this->_tree._header._left;}
	_base_ptr&       _rightmost()
		{return this->_tree._header._right;}
	_const_base_ptr  _rightmost() const
		{return this->_tree._header._right;}

	_link_type       _begin()
		{return static_cast<_link_type>(this->_tree._header._parent);}
	_const_link_type _begin()     const
		{return static_cast<_const_link_type>(this->_tree._header._parent);}
	_link_type       _end()
		{return static_cast<_link_type>(&this->_tree._header);}
	_const_link_type _end()       const
		{return static_cast<_const_link_type>(&this->_tree._header);}

	static
	const_reference  _value(_const_link_type x)
		{return x->_value_field;}
	static
	const Key&      _key(_const_link_type x)
		{return KeyOfValue()(_value(x));}
	static
	_link_type       _left(_base_ptr x)
		{return static_cast<_link_type>(x->_left);}
	static
	_const_link_type _left(_const_base_ptr x)
		{return static_cast<_const_link_type>(x->_left);}
	static
	_link_type       _right(_base_ptr x)
		{return static_cast<_link_type>(x->_right);}
	static
	_const_link_type _right(_const_base_ptr x)
  		{return static_cast<_const_link_type>(x->_right);}
	static
	const_reference  _value(_const_base_ptr x)
  		{return static_cast<_const_link_type>(x)->_value_field;}
	static
	const Key&      _key(_const_base_ptr x)
  		{return KeyOfValue()(_value(x));}
	static
	_base_ptr        _minimum(_base_ptr x)
  		{return _rb_tree_node_base::_minimum(x);}
	static
	_const_base_ptr  _minimum(_const_base_ptr x)
  		{return _rb_tree_node_base::_minimum(x);}
	static
	_base_ptr        _maximum(_base_ptr x)
  		{return _rb_tree_node_base::_maximum(x);}
	static
	_const_base_ptr  _maximum(_const_base_ptr x)
  		{return _rb_tree_node_base::_maximum(x);}

public:
	typedef _rb_tree_iterator<value_type>        iterator;
	typedef _rb_tree_const_iterator<value_type>  const_iterator;
	typedef ft::reverse_iterator<iterator>       reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	iterator   _insert(_const_base_ptr x, _const_base_ptr y, const value_type& v);
	iterator   _insert_lower(_base_ptr x, _base_ptr y, const value_type& v);
	iterator   _insert_equal_lower(const value_type& x);
	_link_type _copy(_const_link_type x, _link_type p);

	void _erase(_link_type x);

	iterator       _lower_bound(_link_type x, _link_type y, const Key& k);
	const_iterator _lower_bound(_const_link_type x, _const_link_type y, const Key& k) const;
	iterator       _upper_bound(_link_type x, _link_type y, const Key& k);
	const_iterator _upper_bound(_const_link_type x, _const_link_type y, const Key& k) const;

public:
	_rb_tree()
	{
	}

	_rb_tree(const Compare& c, const allocator_type& a = allocator_type())
		: _tree(c, a)
	{
	}

	_rb_tree(const _rb_tree& x)
		: _tree(x._tree._keyCompare, x._get_node_allocator())
	{
		if (x._root() != 0)
		{
			this->_root() = this->_copy(x._begin(), x._end());
			this->_leftmost() = this->_minimum(_root());
			this->_rightmost() = this->_maximum(_root());
			this->_tree._node_count = x._tree._node_count;
		}
	}

	~_rb_tree()
	{
		_erase(_begin());
	}

	_rb_tree& operator=(const _rb_tree& x);

	// Accessors
	Compare key_comp() const
		{return _tree._key_compare;}

	iterator       begin()
		{return iterator(static_cast<_link_type>(this->_tree._header._left));}
	const_iterator begin() const
		{return const_iterator(static_cast<_const_link_type>(this->_tree._header._left));}
	iterator       end()
		{return iterator(static_cast<_link_type>(&this->_tree._header));}
	const_iterator end()   const
		{return const_iterator(static_cast<_const_link_type>(&this->_tree._header));}

	reverse_iterator       rbegin()
		{return reverse_iterator(end());}
	const_reverse_iterator rbegin() const
		{return const_reverse_iterator(end());}
	reverse_iterator       rend()
		{return reverse_iterator(begin());}
	const_reverse_iterator rend()   const
		{return const_reverse_iterator(begin());}

	bool empty() const
		{return (_tree._node_count == 0);}

	size_type size()     const
		{return _tree._node_count;}
	size_type max_size() const
		{return _get_node_allocator().max_size();}

	void swap(_rb_tree& t);

	// Insert/erase
	pair<iterator, bool>
		     _insert_unique(const value_type& x);
	iterator _insert_unique_(const_iterator position, const value_type& x);
	template<typename InputIterator>
		void _insert_unique(InputIterator first, InputIterator last);

	iterator _insert_equal(const value_type& x);
	iterator _insert_equal_(const_iterator position, const value_type& x);
	template<typename InputIterator>
		void _insert_equal(InputIterator first, InputIterator last);

private:
	void _erase_aux(const_iterator position);
	void _erase_aux(const_iterator first, const_iterator last);

public:
	void erase(iterator position)
		{_erase_aux(position);}
	void erase(const_iterator position)
		{_erase_aux(position);}
	void erase(iterator first, iterator last)
		{_erase_aux(first, last); }
	void erase(const_iterator first, const_iterator last)
		{_erase_aux(first, last);}

	void      erase(const key_type* first, const key_type* last);
	size_type erase(const key_type& x);

	void clear()
	{
		_erase(_begin());
		_leftmost() = _end();
		_root() = 0;
		_rightmost() = _end();
		_tree._node_count = 0;
	}

	// Set operations.
	iterator       find(const key_type& k);
	const_iterator find(const key_type& k) const;

	size_type count(const key_type& k) const;

	iterator       lower_bound(const key_type& k)
		{return _lower_bound(_begin(), _end(), k);}

	const_iterator lower_bound(const key_type& k) const
		{return _lower_bound(_begin(), _end(), k);}

	iterator       upper_bound(const key_type& k)
		{return _upper_bound(_begin(), _end(), k);} 

	const_iterator upper_bound(const key_type& k) const
		{return _upper_bound(_begin(), _end(), k);}

	pair<iterator, iterator>             equal_range(const key_type& k);
	pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

	// Debugging.
	bool _rb_verify() const;
}; // _rb_tree

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator==(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
           const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator<(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
          const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator!=(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
           const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return !(x == y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator>(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
          const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return y < x;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator<=(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
           const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{ return !(y < x); }

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator>=(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
           const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return !(x < y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline void
swap(_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
     _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	x.swap(y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>&
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
operator=(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x)
{
	if (this != &x)
	{
		clear();
		_tree._key_compare = x._tree._key_compare;
		if (x._root() != 0)
		{
          _root() = _copy(x._begin(), _end());
          _leftmost() = _minimum(_root());
          _rightmost() = _maximum(_root());
          _tree._node_count = x._tree._node_count;
		}
	}
	return *this;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert(_const_base_ptr x, _const_base_ptr p, const Val& v)
{
	bool insert_left = (x != 0 || p == _end()
			|| _tree._key_compare(KeyOfValue()(v), _key(p)));
	_link_type z = _create_node(v);

	_rb_tree_insert_and_rebalance(insert_left, z, const_cast<_base_ptr>(p), this->_tree._header);
	_tree._node_count++;
	return iterator(z);
}

}  // ft

#endif // RB_TREE_HPP
