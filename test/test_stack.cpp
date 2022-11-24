/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:06 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 23:39:44 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_stack( void ) {

	ft::stack<int>		ft_stack;
	std::stack<int>		std_stack;

	for (int i = 10; i < 20; i++) {
		srand(time(NULL));
		int	n = random() % 10;
		std_stack.push(n);
		ft_stack.push(n);
	}

	std::cout << YELLOW << "CONSTRUCTOR TEST" << DEF << std::endl;

	for (int i = 10; i < 30; i++) {
		std_stack.push(i);
		ft_stack.push(i);
	}

	check("empty()", std_stack.empty(), ft_stack.empty());
	check("size()", std_stack.size(), ft_stack.size());

	std::cout << YELLOW << "FUNCTIONS TEST" << DEF << std::endl;

	//ft::stack<int>	new_ft_stack;
	//std::stack<int>	new_std_stack;

	std::cout << MAGENTA << "swap()" << DEF << std::endl;

	//std_stack.swap(new_std_stack); ft_stack.swap(new_ft_stack);
	check("size()", std_stack.size(), ft_stack.size());

	//std_stack.swap(new_std_stack); ft_stack.swap(new_ft_stack);
	check("size()", std_stack.size(), ft_stack.size());
	return 0;
}
