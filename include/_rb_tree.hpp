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

# include <memory>

namespace ft
{

enum _rb_tree_color {_red = false, _black = true};

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

}; // _rb_tree

}  // ft

#endif // RB_TREE_HPP
