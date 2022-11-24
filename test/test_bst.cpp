/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:17 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 19:23:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_bst( void ) {

	std::cout << RED << "test_bst.cpp is not configure" << DEF << std::endl;

	/*ft::map_tree< const int, int, std::allocator< ft::node< const int, int > > > tree;


	//tree.insert(ft::make_pair(4,4));
	tree.insert(ft::make_pair(1,1));
	std::cout << GREEN << "insert 4 => 4 | 1 => 1"  << DEF << std::endl;
	//std::cout << tree.min()->data.first << std::endl;

	//ft::binary_search_tree<int, int>::iterator it = tree.begin();

	//std::cout << it->first << std::endl;

	tree.remove(1);
	std::cout << RED << "remove 1 => 1"  << DEF << std::endl;
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.insert(ft::make_pair(10,2));
	tree.insert(ft::make_pair(5,2));
	std::cout << GREEN << "insert 10 => 2 | 5 => 2"  << DEF << std::endl;
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.remove(5);
	//tree.remove(4);
	tree.remove(10);
	std::cout << RED << "remove 5 => 2"  << DEF << std::endl;
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.clear();
	std::cout << RED << "clear"  << DEF << std::endl;
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.insert(ft::make_pair(1,1));
	tree.insert(ft::make_pair(2,2));
	std::cout << GREEN << "insert 1 => 1 | 2 => 2"  << DEF << std::endl;
	tree.remove(2);
	std::cout << RED << "remove 2 => 2"  << DEF << std::endl;
	tree.insert(ft::make_pair(10,2));
	tree.insert(ft::make_pair(5,2));
	std::cout << GREEN << "insert 10 => 2 | 5 => 2"  << DEF << std::endl;
	tree.remove(10);
	std::cout << RED << "remove 10 => 2"  << DEF << std::endl;
	tree.remove(1);
	std::cout << RED << "remove 1 => 1"  << DEF << std::endl;
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.clear();
	tree.clear();
	//tree.insert(ft::make_pair(10,2));
	//tree.insert(ft::make_pair(5,2));*/
	return 0;
}
