/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:38:10 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/06/05 17:01:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_HPP
# define TESTS_MAP_HPP

# include "map.hpp"
# include <map>
# include <iostream>

#ifndef NAMESPACE
# ifdef STD
#  define NAMESPACE		std
# else
#  define NAMESPACE		ft
# endif
#endif

template <typename T>
class foo
{
public:
	typedef T	value_type;

	foo(void)
		: value(),
		  _verbose(false)
	{
	}

	foo(value_type src, const bool verbose = false)
		: value(src),
		  _verbose(verbose)
	{
	}

	foo(foo const &src, const bool verbose = false)
		: value(src.value),
		  _verbose(verbose)
	{
	}

	~foo(void)
	{
		if (this->_verbose)
			std::cout << "~foo::foo()" << std::endl;
	}

	foo &operator=(value_type src)
	{
		this->value = src;
		return *this;
	}

	foo &operator=(foo const &src)
	{
		if (this->_verbose || src._verbose)
			std::cout << "foo::operator=(foo) CALLED" << std::endl;
		this->value = src.value;
		return *this;
	}

	void m(void)
		{std::cout << "foo::m called [" << this->value << "]" << std::endl;}
	void m(void) const
		{std::cout << "foo::m const called [" << this->value << "]" << std::endl;}
	value_type getValue(void) const
		{return this->value;}
	void switchVerbose(void)
		{this->_verbose = !(this->_verbose);}
	operator value_type(void) const
		{return value_type(this->value);}

private:
	value_type	value;
	bool		_verbose;
};

#define _pair NAMESPACE::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(NAMESPACE::map<T1, T2> &mp)
{
	typename NAMESPACE::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

void	tests_map_constructors();
void	tests_map_bounds();
void	tests_map_comp();
void	tests_map_copy_construct();
void	tests_map_empty();
void	tests_map_erase();
void	tests_map_erase_2();
void	tests_map_insert();
void	tests_map_insert_2();
void	tests_map_find_count();
void	tests_map_ite_arrow();
void	tests_map_ite_n0();
void	tests_map_ite_n1();
void	tests_map_more();
void	tests_map_relational_ope();
void	tests_map_rev_ite_construct();
void	tests_map_rite_arrow();
void	tests_map_rite();
void	tests_map_swap();
void	tests_map_tricky_construct();
void	tests_map_tricky_erase();

#endif // TESTS_MAP_HPP
