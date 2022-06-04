/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:01:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/04 16:08:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "internal/rb_tree.hpp"

namespace ft
{

_rb_tree_node_base*
local_rb_tree_increment(_rb_tree_node_base* x)
{
	if (x->_right != 0)
	{
		x = x->_right;
		while (x->_left != 0)
			x = x->_left;
	}
	else
	{
		_rb_tree_node_base* y = x->_parent;
		while (x == y->_right)
		{
			x = y;
			y = y->_parent;
		}
		if (x->_right != y)
			x = y;
	}
	return x;
}

_rb_tree_node_base*
_rb_tree_increment(_rb_tree_node_base* x)
{
	return local_rb_tree_increment(x);
}

const _rb_tree_node_base*
_rb_tree_increment(const _rb_tree_node_base* x)
{
	return local_rb_tree_increment(const_cast<_rb_tree_node_base*>(x));
}

_rb_tree_node_base*
local_rb_tree_decrement(_rb_tree_node_base* x)
{
	if (x->_color == _node_red && x->_parent->_parent == x)
		x = x->_right;
	else if (x->_left != 0)
	{
		_rb_tree_node_base* y = x->_left;
		while (y->_right != 0)
		y = y->_right;
		x = y;
	}
	else
	{
		_rb_tree_node_base* y = x->_parent;
		while (x == y->_left)
		{
			x = y;
			y = y->_parent;
		}
		x = y;
	}
	return x;
}

_rb_tree_node_base*
_rb_tree_decrement(_rb_tree_node_base* x)
{
	return local_rb_tree_decrement(x);
}

const _rb_tree_node_base*
_rb_tree_decrement(const _rb_tree_node_base* x)
{
	return local_rb_tree_decrement(const_cast<_rb_tree_node_base*>(x));
}

void
local_rb_tree_rotate_left(_rb_tree_node_base* const x,
                          _rb_tree_node_base*& root)
{
	_rb_tree_node_base* const y = x->_right;
	x->_right = y->_left;
	if (y->_left !=0)
		y->_left->_parent = x;
	y->_parent = x->_parent;
	if (x == root)
		root = y;
	else if (x == x->_parent->_left)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_left = x;
	x->_parent = y;
}

void
local_rb_tree_rotate_right(_rb_tree_node_base* const x,
                           _rb_tree_node_base*& root)
{
	_rb_tree_node_base* const y = x->_left;
	x->_left = y->_right;
	if (y->_right != 0)
		y->_right->_parent = x;
	y->_parent = x->_parent;
	if (x == root)
		root = y;
	else if (x == x->_parent->_right)
		x->_parent->_right = y;
	else
		x->_parent->_left = y;
	y->_right = x;
	x->_parent = y;
}

void
_rb_tree_insert_and_rebalance(const bool insert_left,
                              _rb_tree_node_base* x,
                              _rb_tree_node_base* p,
                              _rb_tree_node_base& header)
{
	_rb_tree_node_base *& root = header._parent;
	// Initialize fields in new node to insert.
	x->_parent = p;
	x->_left = 0;
	x->_right = 0;
	x->_color = _node_red;
	// Insert.
	// Make new node child of parent and maintain root, leftmost and
	// rightmost nodes.
	// N.B. First node is always inserted left.
	if (insert_left)
	{
		p->_left = x; // also makes leftmost = x when p == &header
		if (p == &header)
		{
		header._parent = x;
		header._right = x;
		}
		else if (p == header._left)
		header._left = x; // maintain leftmost pointing to min node
	}
	else
	{
		p->_right = x;
		if (p == header._right)
		header._right = x; // maintain rightmost pointing to max node
	}
	// Rebalance.
	while (x != root && x->_parent->_color == _node_red)
	{
		_rb_tree_node_base* const xpp = x->_parent->_parent;
		if (x->_parent == xpp->_left)
		{
			_rb_tree_node_base* const y = xpp->_right;
			if (y && y->_color == _node_red)
			{
				x->_parent->_color = _node_black;
				y->_color = _node_black;
				xpp->_color = _node_red;
				x = xpp;
			}
			else
			{
				if (x == x->_parent->_right)
				{
					x = x->_parent;
					local_rb_tree_rotate_left(x, root);
				}
				x->_parent->_color = _node_black;
				xpp->_color = _node_red;
				local_rb_tree_rotate_right(xpp, root);
			}
		}
		else
		{
			_rb_tree_node_base* const y = xpp->_left;
			if (y && y->_color == _node_red)
			{
				x->_parent->_color = _node_black;
				y->_color = _node_black;
				xpp->_color = _node_red;
				x = xpp;
			}
			else
			{
				if (x == x->_parent->_left)
				{
					x = x->_parent;
					local_rb_tree_rotate_right(x, root);
				}
				x->_parent->_color = _node_black;
				xpp->_color = _node_red;
				local_rb_tree_rotate_left(xpp, root);
			}
		}
	}
	root->_color = _node_black;
}

_rb_tree_node_base*
_rb_tree_rebalance_for_erase(_rb_tree_node_base* const z,
                               _rb_tree_node_base& header)
  {
	_rb_tree_node_base *& root = header._parent;
	_rb_tree_node_base *& leftmost = header._left;
	_rb_tree_node_base *& rightmost = header._right;
	_rb_tree_node_base* y = z;
	_rb_tree_node_base* x = 0;
	_rb_tree_node_base* x_parent = 0;
	if (y->_left == 0) // z has at most one non-null child. y == z.
		x = y->_right; // x might be null.
	else
	{
		if (y->_right == 0) // z has exactly one non-null child. y == z.
			x = y->_left; // x is not null.
		else
		{
			// z has two non-null children.  Set y to
			y = y->_right; //   z's successor.  x might be null.
			while (y->_left != 0)
				y = y->_left;
			x = y->_right;
		}
	}
	if (y != z)
	{
		// relink y in place of z.  y is z's successor
		z->_left->_parent = y;
		y->_left = z->_left;
		if (y != z->_right)
		{
			x_parent = y->_parent;
			if (x) x->_parent = y->_parent;
			y->_parent->_left = x; // y must be a child of _left
			y->_right = z->_right;
			z->_right->_parent = y;
		}
		else
			x_parent = y;
		if (root == z)
			root = y;
		else if (z->_parent->_left == z)
			z->_parent->_left = y;
		else
			z->_parent->_right = y;
		y->_parent = z->_parent;
		swap(y->_color, z->_color);
		y = z;
		// y now points to node to be actually deleted
	}
	else // y == z
	{
		x_parent = y->_parent;
		if (x)
			x->_parent = y->_parent;
		if (root == z)
			root = x;
		else
		{
			if (z->_parent->_left == z)
				z->_parent->_left = x;
			else
			z->_parent->_right = x;
		}
		if (leftmost == z)
		{
			if (z->_right == 0) // z->_left must be null also
				leftmost = z->_parent;
			// makes leftmost == _header if z == root
			else
				leftmost = _rb_tree_node_base::_minimum(x);
		}
		if (rightmost == z)
		{
			if (z->_left == 0) // z->_right must be null also
			rightmost = z->_parent;
			// makes rightmost == _header if z == root
			else // x == z->_left
			rightmost = _rb_tree_node_base::_maximum(x);
		}
	}
    if (y->_color != _node_red)
	{
	while (x != root && (x == 0 || x->_color == _node_black))
	{
		if (x == x_parent->_left)
		{
			_rb_tree_node_base* w = x_parent->_right;
			if (w->_color == _node_red)
			{
				w->_color = _node_black;
				x_parent->_color = _node_red;
				local_rb_tree_rotate_left(x_parent, root);
				w = x_parent->_right;
			}
			if ((w->_left == 0 || w->_left->_color == _node_black)
				&& (w->_right == 0 || w->_right->_color == _node_black))
			{
				w->_color = _node_red;
				x = x_parent;
				x_parent = x_parent->_parent;
			}
			else
			{
				if (w->_right == 0 || w->_right->_color == _node_black)
				{
					w->_left->_color = _node_black;
					w->_color = _node_red;
					local_rb_tree_rotate_right(w, root);
					w = x_parent->_right;
				}
				w->_color = x_parent->_color;
				x_parent->_color = _node_black;
				if (w->_right)
					w->_right->_color = _node_black;
				local_rb_tree_rotate_left(x_parent, root);
				break;
			}
		}
		else
		{
			// same as above, with _right <-> _left.
			_rb_tree_node_base* w = x_parent->_left;
			if (w->_color == _node_red)
			{
				w->_color = _node_black;
				x_parent->_color = _node_red;
				local_rb_tree_rotate_right(x_parent, root);
				w = x_parent->_left;
			}
			if ((w->_right == 0 || w->_right->_color == _node_black)
				&& (w->_left == 0 || w->_left->_color == _node_black))
			{
				w->_color = _node_red;
				x = x_parent;
				x_parent = x_parent->_parent;
			}
			else
			{
				if (w->_left == 0 || w->_left->_color == _node_black)
				{
					w->_right->_color = _node_black;
					w->_color = _node_red;
					local_rb_tree_rotate_left(w, root);
					w = x_parent->_left;
				}
				w->_color = x_parent->_color;
				x_parent->_color = _node_black;
				if (w->_left)
					w->_left->_color = _node_black;
				local_rb_tree_rotate_right(x_parent, root);
				break;
			}
		}
	}
	if (x)
		x->_color = _node_black;
	}
	return y;
}

}  // ft
