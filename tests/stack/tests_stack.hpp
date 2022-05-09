/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/09 16:46:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_HPP
# define TESTS_STACK_HPP

# include "stack.hpp"
# include <stack>
# include <iostream>
# include <memory>

#ifndef NAMESPACE
# ifdef STD
#  define NAMESPACE		std
# else
#  define NAMESPACE		ft
# endif
#endif

void	test_stack();

#endif // TESTS_STACK_HPP
