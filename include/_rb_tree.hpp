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

# include "algorithm.hpp"
# include "functional.hpp"
# include "iterator.hpp"
# include "utility.hpp"
# include <memory>

namespace ft
{

enum _rb_tree_color {_node_red = false, _node_black = true};

struct _rb_tree_node_base
{
	typedef _rb_tree_node_base*       _base_ptr;
	typedef const _rb_tree_node_base* _const_base_ptr;

	_rb_tree_color _color;
	_base_ptr      _parent;
	_base_ptr      _left;
	_base_ptr      _right;

	static _base_ptr
	_minimum(_base_ptr x)
	{
		while (x->_left != 0)
			x = x->_left;
		return x;
	}

	static _const_base_ptr
	_minimum(_const_base_ptr x)
	{
		while (x->_left != 0)
			x = x->_left;
		return x;
	}

	static _base_ptr
	_maximum(_base_ptr x)
	{
		while (x->_right != 0)
			x = x->_right;
		return x;
	}

	static _const_base_ptr
	_maximum(_const_base_ptr x)
	{
		while (x->_right != 0)
			x = x->_right;
		return x;
	}
};

template <class Val>
struct _rb_tree_node
	: public _rb_tree_node_base
{
	typedef _rb_tree_node<Val*> _link_type;

	Val _value_field;
};

_rb_tree_node_base* local_rb_tree_increment(_rb_tree_node_base* x) throw ();
_rb_tree_node_base* _rb_tree_increment(_rb_tree_node_base* x) throw ();
const
_rb_tree_node_base* _rb_tree_increment(const _rb_tree_node_base* x) throw ();

_rb_tree_node_base* local_rb_tree_decrement(_rb_tree_node_base* x) throw ();
_rb_tree_node_base* _rb_tree_decrement(_rb_tree_node_base* x) throw ();
const
_rb_tree_node_base* _rb_tree_decrement(const _rb_tree_node_base* x) throw ();

void local_rb_tree_rotate_left(_rb_tree_node_base* const x,
                               _rb_tree_node_base*& root);
void local_rb_tree_rotate_right(_rb_tree_node_base* const x,
                                _rb_tree_node_base*& root);
void _rb_tree_insert_and_rebalance(const bool insert_left,
                                   _rb_tree_node_base* x,
                                   _rb_tree_node_base* p,
                                   _rb_tree_node_base& header) throw ();
_rb_tree_node_base*
_rb_tree_rebalance_for_erase(_rb_tree_node_base* const z,
                             _rb_tree_node_base& header) throw ();

template <class Tp>
struct _rb_tree_iterator
{
	typedef Tp  value_type;
	typedef Tp* pointer;
	typedef Tp& reference;

	typedef bidirectional_iterator_tag iterator_category;
	typedef std::ptrdiff_t             difference_type;

	typedef _rb_tree_iterator<Tp>         _self;
	typedef _rb_tree_node_base::_base_ptr _base_ptr;
	typedef _rb_tree_node<Tp>*            _link_type;

	_base_ptr _node;

	_rb_tree_iterator()
		: _node()
	{
	}
	
	explicit
	_rb_tree_iterator(_link_type x)
		: _node(x)
	{
	}

	reference
	operator*() const
		{return static_cast<_link_type>(_node)->_value_field;}

	pointer
	operator->() const
		{return &(static_cast<_link_type>(_node)->_value_field);}

	_self&
	operator++()
	{
		_node = _rb_tree_increment(_node);
		return *this;
	}

	_self
	operator++(int)
	{
		_self tmp = *this;
		_node = _rb_tree_increment(_node);
		return tmp;
	}

	_self&
	operator--()
	{
		_node = _rb_tree_decrement(_node);
		return *this;
	}

	_self
	operator--(int)
	{
		_self tmp = *this;
		_node = _rb_tree_decrement(_node);
		return tmp;
	}

	bool
	operator==(const _self& x) const
		{return _node == x._node;}

	bool
	operator!=(const _self& x) const
		{return _node != x._node;}
};

template <class Tp>
struct _rb_tree_const_iterator
{
	typedef Tp        value_type;
	typedef const Tp* pointer;
	typedef const Tp& reference;

	typedef _rb_tree_iterator<Tp> iterator;

	typedef bidirectional_iterator_tag iterator_category;
	typedef std::ptrdiff_t             difference_type;

	typedef _rb_tree_const_iterator<Tp>         _self;
	typedef _rb_tree_node_base::_const_base_ptr _base_ptr;
	typedef const _rb_tree_node<Tp>*            _link_type;

	_base_ptr _node;

	_rb_tree_const_iterator()
		: _node()
	{
	}

	explicit
	_rb_tree_const_iterator(_link_type x)
		: _node(x)
	{
	}

	_rb_tree_const_iterator(const iterator& it)
		: _node(it._node)
	{
	}

	iterator
	_const_cast() const
	{
		return iterator(static_cast<
			typename iterator::_link_type>(const_cast<
				typename iterator::_base_ptr>(_node)));
	}

	reference
	operator*() const
		{return static_cast<_link_type>(_node)->_value_field;}
	
	pointer
	operator->() const
		{return &(static_cast<_link_type>(_node)->_value_field);}

	_self&
	operator++()
	{
		_node = _rb_tree_increment(_node);
		return *this;
	}

	_self
	operator++(int)
	{
		_self tmp = *this;
		_node = _rb_tree_increment(_node);
		return (tmp);
	}

	_self&
	operator--()
	{
		_node = _rb_tree_decrement(_node);
		return *this;
	}

	_self
	operator--(int)
	{
		_self tmp = *this;
		_node = _rb_tree_decrement(_node);
		return (tmp);
	}

	bool
	operator==(const _self& x) const
		{return _node == x._node;}

	bool
	operator!=(const _self& x) const
		{return _node != x._node;}
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
		return *static_cast<const _node_allocator*>(&this->_tree);
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
	_clone_node(_const_link_type x)
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
	};

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
	const Key&       _key(_const_link_type x)
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
	iterator   _insert_equallower(const value_type& x);
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
		: _tree(x._tree._key_compare, x._get_node_allocator())
	{
		if (x._root() != 0)
		{
			_root() = this->_copy(x._begin(), _end());
			_leftmost() = _minimum(_root());
			_rightmost() = _maximum(_root());
			_tree._node_count = x._tree._node_count;
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
	iterator _insert_unique(const_iterator position, const value_type& x);
	template<typename InputIterator>
		void _insert_unique(InputIterator first, InputIterator last);

	iterator _insert_equal(const value_type& x);
	iterator _insert_equal(const_iterator position, const value_type& x);
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

	// Debugging
	//bool _rb_verify() const;
};

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

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_lower(_base_ptr x, _base_ptr p, const Val& v)
{
	bool insert_left = (x != 0 || p == _end()
			|| !_tree._key_compare(_key(p), KeyOfValue()(v)));
	_link_type z = _create_node(v);

	_rb_tree_insert_and_rebalance(insert_left, z, p, this->_tree._header);
	_tree._node_count++;
	return iterator(z);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_equallower(const Val& v)
{
	_link_type x = _begin();
	_link_type y = _end();
	while (x != 0)
	{
		y = x;
		x = !_tree._key_compare(_key(x), KeyOfValue()(v)) ?
		_left(x) : _right(x);
	}
	return _insert_lower(x, y, v);
}

template<typename Key, typename Val, typename KoV,
typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KoV, Compare, Alloc>::_link_type
_rb_tree<Key, Val, KoV, Compare, Alloc>::
_copy(_const_link_type x, _link_type p)
{
	// Structural copy.  x and p must be non-null.
	_link_type top = _clone_node(x);
	top->_parent = p;
	try
	{
		if (x->_right)
			top->_right = _copy(_right(x), top);
		p = top;
		x = _left(x);
		while (x != 0)
		{
			_link_type y = _clone_node(x);
			p->_left = y;
			y->_parent = p;
			if (x->_right)
				y->_right = _copy(_right(x), y);
			p = y;
			x = _left(x);
		}
	}
	catch(...)
	{
		_erase(top);
		throw;
	}
	return top;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_erase(_link_type x)
{
	// Erase without rebalancing.
	while (x != 0)
	{
		_erase(_right(x));
		_link_type y = _left(x);
		_destroy_node(x);
		x = y;
	}
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_lower_bound(_link_type x, _link_type y, const Key& k)
{
	while (x != 0)
	{
		if (!_tree._key_compare(_key(x), k))
			y = x, x = _left(x);
		else
			x = _right(x);
	}
	return iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_lower_bound(_const_link_type x, _const_link_type y, const Key& k) const
{
	while (x != 0)
	{
		if (!_tree._key_compare(_key(x), k))
			y = x, x = _left(x);
		else
			x = _right(x);
	}
	return const_iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_upper_bound(_link_type x, _link_type y, const Key& k)
{
	while (x != 0)
	{
		if (_tree._key_compare(k, _key(x)))
			y = x, x = _left(x);
		else
			x = _right(x);
	}
	return iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_upper_bound(_const_link_type x, _const_link_type y, const Key& k) const
{
	while (x != 0)
	{
		if (_tree._key_compare(k, _key(x)))
			y = x, x = _left(x);
		else
			x = _right(x);
	}
	return const_iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
pair<typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator,
     typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator>
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
equal_range(const Key& k)
{
	_link_type x = _begin();
	_link_type y = _end();
	while (x != 0)
	{
		if (_tree._key_compare(_key(x), k))
			x = _right(x);
		else if (_tree._key_compare(k, _key(x)))
			y = x, x = _left(x);
		else
		{
			_link_type xu(x), yu(y);
			y = x, x = _left(x);
			xu = _right(xu);
			return pair<iterator, iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
		}
	}
	return pair<iterator, iterator>(iterator(y), iterator(y));
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
pair<typename _rb_tree<Key, Val, KeyOfValue,
Compare, Alloc>::const_iterator,
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator>
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
equal_range(const Key& k) const
{
	_const_link_type x = _begin();
	_const_link_type y = _end();
	while (x != 0)
	{
		if (_tree._key_compare(_key(x), k))
			x = _right(x);
		else if (_tree._key_compare(k, _key(x)))
			y = x, x = _left(x);
		else
		{
			_const_link_type xu(x), yu(y);
			y = x, x = _left(x);
			xu = _right(xu);
			return pair<const_iterator, const_iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
		}
	}
	return pair<const_iterator, const_iterator>(const_iterator(y),
	const_iterator(y));
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
swap(_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& t)
{
	if (_root() == 0)
	{
		if (t._root() != 0)
		{
			_root() = t._root();
			_leftmost() = t._leftmost();
			_rightmost() = t._rightmost();
			_root()->_parent = _end();

			t._root() = 0;
			t._leftmost() = t._end();
			t._rightmost() = t._end();
		}
	}
	else if (t._root() == 0)
	{
		t._root() = _root();
		t._leftmost() = _leftmost();
		t._rightmost() = _rightmost();
		t._root()->_parent = t._end();
		_root() = 0;
		_leftmost() = _end();
		_rightmost() = _end();
	}
	else
	{
		ft::swap(_root(), t._root());
		ft::swap(_leftmost(),t._leftmost());
		ft::swap(_rightmost(),t._rightmost());
		_root()->_parent = _end();
		t._root()->_parent = t._end();
	}
	// No need to swap header's color as it does not change.
	ft::swap(this->_tree._node_count, t._tree._node_count);
	ft::swap(this->_tree._key_compare, t._tree._key_compare);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
pair<typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator, bool>
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_unique(const Val& v)
{
	_link_type x = _begin();
	_link_type y = _end();
	bool comp = true;

	while (x != 0)
	{
		y = x;
		comp = _tree._key_compare(KeyOfValue()(v), _key(x));
		x = comp ? _left(x) : _right(x);
	}
	iterator j = iterator(y);
	if (comp)
	{
		if (j == begin())
			return pair<iterator, bool>(_insert(x, y, v), true);
		else
			j--;
	}
	if (_tree._key_compare(_key(j._node), KeyOfValue()(v)))
		return pair<iterator, bool>(_insert(x, y, v), true);
	return pair<iterator, bool>(j, false);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_equal(const Val& v)
{
	_link_type x = _begin();
	_link_type y = _end();

	while (x != 0)
	{      y = x;
		x = _tree._key_compare(KeyOfValue()(v), _key(x)) ?
		_left(x) : _right(x);
	}
	return _insert(x, y, v);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_unique(const_iterator position, const Val& v)
{
	// end()
	if (position._node == _end())
	{
		if (size() > 0 && _tree._key_compare(_key(_rightmost()), KeyOfValue()(v)))
			return _insert(0, _rightmost(), v);
		else
			return _insert_unique(v).first;
	}
	else if (_tree._key_compare(KeyOfValue()(v), _key(position._node)))
	{
		// First, try before...
		const_iterator before = position;
		if (position._node == _leftmost()) // begin()
			return _insert(_leftmost(), _leftmost(), v);
		else if (_tree._key_compare(_key((--before)._node), KeyOfValue()(v)))
		{
			if (_right(before._node) == 0)
				return _insert(0, before._node, v);
			else
				return _insert(position._node, position._node, v);
		}
		else
			return _insert_unique(v).first;
	}
	else if (_tree._key_compare(_key(position._node), KeyOfValue()(v)))
	{
		// ... then try after.
		const_iterator after = position;
		if (position._node == _rightmost())
			return _insert(0, _rightmost(), v);
		else if (_tree._key_compare(KeyOfValue()(v), _key((++after)._node)))
		{
			if (_right(position._node) == 0)
				return _insert(0, position._node, v);
			else
				return _insert(after._node, after._node, v);
		}
		else
			return _insert_unique(v).first;
	}
	else // Equivalent keys.
		return position._const_cast();
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_equal(const_iterator position, const Val& v)
{
	// end()
	if (position._node == _end())
	{
		if (size() > 0 && !_tree._key_compare(KeyOfValue()(v), _key(_rightmost())))
			return _insert(0, _rightmost(), v);
		else
			return _insert_equal(v);
	}
	else if (!_tree._key_compare(_key(position._node), KeyOfValue()(v)))
	{
		// First, try before...
		const_iterator before = position;
		if (position._node == _leftmost()) // begin()
			return _insert(_leftmost(), _leftmost(), v);
		else if (!_tree._key_compare(KeyOfValue()(v), _key((--before)._node)))
		{
			if (_right(before._node) == 0)
				return _insert(0, before._node, v);
			else
				return _insert(position._node, position._node, v);
		}
		else
			return _insert_equal(v);
	}
	else
	{
		// ... then try after.  
		const_iterator after = position;
		if (position._node == _rightmost())
			return _insert(0, _rightmost(), v);
		else if (!_tree._key_compare(_key((++after)._node), KeyOfValue()(v)))
		{
			if (_right(position._node) == 0)
				return _insert(0, position._node, v);
			else
				return _insert(after._node, after._node, v);
		}
		else
			return _insert_equallower(v);
	}
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
template<class II>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_unique(II first, II last)
{
	for (; first != last; ++first)
		_insert_unique(end(), *first);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
template<class II>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_insert_equal(II first, II last)
{
	for (; first != last; ++first)
		_insert_equal(end(), *first);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_erase_aux(const_iterator position)
{
	_link_type y = static_cast<_link_type>(_rb_tree_rebalance_for_erase(const_cast<
		_base_ptr>(position._node),this->_tree._header));
	_destroy_node(y);
	_tree._node_count--;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
_erase_aux(const_iterator first, const_iterator last)
{
	if (first == begin() && last == end())
		clear();
	else
		while (first != last)
			erase(first++);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::size_type
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
erase(const Key& x)
{
	pair<iterator, iterator> p = equal_range(x);
	const size_type old_size = size();
	erase(p.first, p.second);
	return old_size - size();
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
void
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
erase(const Key* first, const Key* last)
{
	while (first != last)
		erase(*first++);
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
find(const Key& k)
{
	iterator j = _lower_bound(_begin(), _end(), k);
	return (j == end() || _tree._key_compare(k, _key(j._node))) ? end() : j;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
find(const Key& k) const
{
	const_iterator j = _lower_bound(_begin(), _end(), k);
	return (j == end() || _tree._key_compare(k, _key(j._node))) ? end() : j;
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
typename _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::size_type
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::
count(const Key& k) const
{
	pair<const_iterator, const_iterator> p = equal_range(k);
	const size_type n = ft::distance(p.first, p.second);
	return n;
}

unsigned int
_rb_tree_black_count(const _rb_tree_node_base* node, const _rb_tree_node_base* root) throw ();

/*
template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
bool
_rb_tree<Key, Val, KeyOfValue, Compare, Alloc>::rb_verify() const
{
if (_tree._node_count == 0 || begin() == end())
return _tree._node_count == 0 && begin() == end()
&& this->_tree._header._left == _end()
&& this->_tree._header._right == _end();

unsigned int len = _rb_tree_black_count(_leftmost(), _root());
for (const_iterator it = begin(); it != end(); ++it)
{
_const_link_type x = static_cast<_const_link_type>(it._node);
_const_link_type L = _left(x);
_const_link_type R = _right(x);

if (x->_color == _red)
if ((L && L->_color == _red)
|| (R && R->_color == _red))
return false;

if (L && _tree._key_compare(_key(x), _key(L)))
return false;
if (R && _tree._key_compare(_key(R), _key(x)))
return false;

	if (!L && !R && _rb_tree_black_count(x, _root()) != len)
		return false;
	}
	if (_leftmost() != _rb_tree_node_base::_minimum(_root()))
		return false;
	if (_rightmost() != _rb_tree_node_base::_maximum(_root()))
		return false;
	return true;
}
*/

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator==(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
           const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template<typename Key, typename Val, typename KeyOfValue,
         typename Compare, typename Alloc>
inline bool
operator<(const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
          const _rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
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

}  // ft

#endif // RB_TREE_HPP
