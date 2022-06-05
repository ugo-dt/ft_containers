/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:34:48 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"

#define T1 int
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef NAMESPACE::map<T1, T2, ft_more> ft_mp;
typedef NAMESPACE::map<T1, T2, ft_more>::iterator ft_mp_it;

void	tests_map_more()
{
	ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);
}
