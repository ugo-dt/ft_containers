/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:49:14 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/08 15:13:17 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
#ifdef STD
	std::cout << "Testing with std" << std::endl;
#else
	std::cout << "Testing with ft" << std::endl;
#endif
	tests_vector_constructors();
	return (0);
}
