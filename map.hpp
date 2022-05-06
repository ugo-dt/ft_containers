/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:02 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/04 19:41:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include <memory>     // std::allocator
# include <functional> // std::less

namespace ft
{

template <class Key, class Tp, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, Tp> > >
class map
{
	map();
	~map();
}; // map

}  // ft

#endif // MAP_HPP
