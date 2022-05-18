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

#ifndef INTERNAL_RB_TREE_HPP
# define INTERNAL_RB_TREE_HPP

/**
 * @file "_rb_tree.hpp"
 * 
 * This is an internal header file, included by other library headers.
 * Do not use it directly.
 */

namespace ft
{

template <class Tp, class Compare, class Allocator>
class _rb_tree
{
public:
	typedef Tp        value_type;
	typedef Compare   value_compare;
	typedef Allocator allocator_type;
};

}  // ft

#endif // INTERNAL_RB_TREE_HPP
