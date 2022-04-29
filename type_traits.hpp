/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:45:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/29 21:54:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_H
# define TYPE_TRAITS_H

template <bool B, class Tp = void>
struct enable_if
{};

template <class Tp>
struct enable_if<true, Tp>
{
	typedef T type;
};

#endif // TYPE_TRAITS_H
