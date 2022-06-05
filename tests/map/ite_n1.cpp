/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ite_n1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:34:47 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:47 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"

#define T1 int
#define T2 int

void	tests_map_ite_n1()
{
	NAMESPACE::map<T1, T2> const mp;
//	NAMESPACE::map<T1, T2>::iterator it = mp.begin(); // <-- error expected
}
