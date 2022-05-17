/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:27:40 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/17 11:28:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_HPP
# define _TREE_HPP

/**
 * This is an internal header file, included by other library headers.
 * Do not use it directly.
 */

namespace ft
{

template <class Tp, class Compare, class Allocator>
class _tree
{
public:
	typedef Tp        value_type;
	typedef Compare   value_compare;
	typedef Allocator allocator_type;
}; // _tree

}  // ft

#endif // _TREE_HPP
