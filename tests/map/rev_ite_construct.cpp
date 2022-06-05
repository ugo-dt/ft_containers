/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_ite_construct.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:34:52 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"

#define T1 int
#define T2 int

void	tests_map_rev_ite_construct()
{
	NAMESPACE::map<T1, T2> mp;
	NAMESPACE::map<T1, T2>::iterator it = mp.begin();
	NAMESPACE::map<T1, T2>::const_iterator cit = mp.begin();

	NAMESPACE::map<T1, T2>::reverse_iterator rit(it);

	NAMESPACE::map<T1, T2>::const_reverse_iterator crit(rit);
	NAMESPACE::map<T1, T2>::const_reverse_iterator crit_(it);
	NAMESPACE::map<T1, T2>::const_reverse_iterator crit_2(cit);

	/* error expected
	NAMESPACE::map<T1, T2>::reverse_iterator rit_(crit);
	NAMESPACE::map<T1, T2>::reverse_iterator rit2(cit);
	NAMESPACE::map<T1, T2>::iterator it2(rit);
	NAMESPACE::map<T1, T2>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
}
