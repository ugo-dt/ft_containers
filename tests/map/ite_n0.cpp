/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ite_n0.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:34:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:46 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"

#define T1 int
#define T2 int

void	tests_map_ite_n0()
{
	NAMESPACE::map<T1, T2> mp;
	mp[1] = 2;

	NAMESPACE::map<T1, T2>::const_iterator ite = mp.begin();
//	*ite = 42; // < -- error
	(void)ite;
}
