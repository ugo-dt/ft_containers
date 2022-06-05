/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite_arrow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:34:53 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:53 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"
#include <list>

#define T1 float
#define T2 foo<int>
typedef _pair<const T1, T2> T3;

void	tests_map_rite_arrow()
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 - i, (i + 1) * 7));

	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	NAMESPACE::map<T1, T2>::reverse_iterator it(mp.rbegin());
	NAMESPACE::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);
}
