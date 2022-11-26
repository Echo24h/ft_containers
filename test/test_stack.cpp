/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:06 by gborne            #+#    #+#             */
/*   Updated: 2022/11/26 19:01:26 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_stack( void ) {

	ft::stack<int>		ft_stack;
	std::stack<int>		std_stack;

	std::cout << MAGENTA << "size() / empty() / push()" << DEF << std::endl;

	check("empty()", std_stack.empty(), ft_stack.empty());
	check("size()", std_stack.size(), ft_stack.size());

	for (int i = 10; i < 20; i++) {
		srand(time(NULL));
		int	n = random() % 10;
		std_stack.push(n);
		ft_stack.push(n);
	}

	check("empty()", std_stack.empty(), ft_stack.empty());
	check("size()", std_stack.size(), ft_stack.size());

	std::cout << YELLOW << "CONSTRUCTOR TEST" << DEF << std::endl;

	for (int i = 10; i < 30; i++) {
		std_stack.push(i);
		ft_stack.push(i);
	}

	{

		std::cout << MAGENTA << "stack(stack)" << DEF << std::endl;

		ft::stack<int>	new_ft_stack(ft_stack);
		std::stack<int>	new_std_stack(std_stack);

		check("empty()", new_std_stack.empty(), new_ft_stack.empty());
		check("size()", new_std_stack.size(), new_ft_stack.size());
		check("top()", new_std_stack.top(), new_ft_stack.top());

		std::cout << MAGENTA << "stack = stack" << DEF << std::endl;

		ft_stack = new_ft_stack;
		std_stack = new_std_stack;

		check("empty()", std_stack.empty(), ft_stack.empty());
		check("size()", std_stack.size(), ft_stack.size());
		check("top()", std_stack.top(), ft_stack.top());



	}
	std::cout << YELLOW << "FUNCTIONS TEST" << DEF << std::endl;

	ft::stack<int>	new_ft_stack;
	std::stack<int>	new_std_stack;

	std::cout << MAGENTA << "swap() / pop() / top()" << DEF << std::endl;

	std_stack.swap(new_std_stack); ft_stack.swap(new_ft_stack);
	check("size()", std_stack.size(), ft_stack.size());
	//check("top()", std_stack.top(), ft_stack.top());

	std_stack.swap(new_std_stack); ft_stack.swap(new_ft_stack);
	check("size()", std_stack.size(), ft_stack.size());
	check("top()", std_stack.top(), ft_stack.top());

	for (int i = 20; i != 0; i--)
		std_stack.pop(), ft_stack.pop();

	check("pop() (x20)", std_stack.size(), ft_stack.size());
	check("top()", std_stack.top(), ft_stack.top());

	std::cout << YELLOW << "OPERATORS TEST" << DEF << std::endl;

	check("==", std_stack == new_std_stack, ft_stack == new_ft_stack);
	check("!=", std_stack != new_std_stack, ft_stack != new_ft_stack);
	check("<", std_stack < new_std_stack, ft_stack < new_ft_stack);
	check("<=", std_stack <= new_std_stack, ft_stack <= new_ft_stack);
	check(">", std_stack > new_std_stack, ft_stack > new_ft_stack);
	check(">=", std_stack >= new_std_stack, ft_stack >= new_ft_stack);
	std_stack.pop(), ft_stack.pop();
	check("pop()", std_stack.size(), ft_stack.size());
	check("==", std_stack == new_std_stack, ft_stack == new_ft_stack);
	check("!=", std_stack != new_std_stack, ft_stack != new_ft_stack);
	check("<", std_stack < new_std_stack, ft_stack < new_ft_stack);
	check("<=", std_stack <= new_std_stack, ft_stack <= new_ft_stack);
	check(">", std_stack > new_std_stack, ft_stack > new_ft_stack);
	check(">=", std_stack >= new_std_stack, ft_stack >= new_ft_stack);



	return 0;
}
