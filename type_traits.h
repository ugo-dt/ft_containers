/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:45:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/28 11:49:14 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_H
# define TYPE_TRAITS_H

template <bool B, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T>
{
	typedef T type;
};

#endif // TYPE_TRAITS_H
