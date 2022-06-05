/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:37:49 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:34:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_map.hpp"

template<typename Map>
void print_map(Map& m)
{
   std::cout << '{';
   for(typename Map::iterator it = m.begin(); it != m.end(); it++)
        std::cout << it->first << ':' << it->second << ' ';
   std::cout << "}\n";
}

bool fncomp(char lhs, char rhs)
{
	return lhs<rhs;
}

struct classcomp
{
	bool operator()(const char& lhs, const char& rhs) const
		{return lhs<rhs;}
};

void	tests_map_constructors()
{
	std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::map<char,int> second(first.begin(),first.end());
	std::map<char,int> third(second);
	std::map<char,int,classcomp> fourth;                 // class as Compare
	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	print_map(first);
	print_map(second);
	print_map(third);
	print_map(fourth);
	print_map(fifth);

	// (1) Default constructor
	std::map<std::string, int> map1;
	map1["something"] = 69;
	map1["anything"] = 199;
	map1["that thing"] = 50;
	std::cout << "map1 = "; print_map(map1);

	// (2) Range constructor
	std::map<std::string, int> iter(map1.find("anything"), map1.end());
	std::cout << "\niter = "; print_map(iter);
	std::cout << "map1 = "; print_map(map1);

	// (3) Copy constructor
	std::map<std::string, int> copied(map1);
	std::cout << "\ncopied = "; print_map(copied);
	std::cout << "map1 = "; print_map(map1);

	// (4) Move constructor
	std::map<std::string, int> moved(std::move(map1));
	std::cout << "\nmoved = "; print_map(moved);
	std::cout << "map1 = "; print_map(map1);

	{
		std::map<char,int> first;
		std::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n'; print_map(first);
		std::cout << "Size of second: " << second.size() << '\n'; print_map(second);
	}
}
