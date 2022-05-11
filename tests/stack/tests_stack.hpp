/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_stack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/11 21:07:45 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_HPP
# define TESTS_STACK_HPP

# include "stack.hpp"
# include "vector.hpp"
# include <iostream>
# include <memory>
# include <stack>
# include <vector>

#ifndef NAMESPACE
# ifdef STD
#  define NAMESPACE		std
# else
#  define NAMESPACE		ft
# endif
#endif

void	tests_stack_constructor();
void	tests_stack_functions();

#endif // TESTS_STACK_HPP
