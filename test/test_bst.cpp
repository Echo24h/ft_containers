/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:17 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 01:23:44 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_bst( void ) {

	ft::map_tree< const int, int, std::allocator< ft::node< const int, int > > > tree;

	tree.insert(ft::make_pair(1,1));
	//std::cout << tree.min()->data.first << std::endl;

	//ft::binary_search_tree<int, int>::iterator it = tree.begin();

	//std::cout << it->first << std::endl;

	tree.remove(1);
	tree.inOrder();
	std::cout << "1 supprimé" << std::endl;
	tree.insert(ft::make_pair(10,2));
	tree.insert(ft::make_pair(5,2));
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.clear();
	tree.inOrder();
	std::cout << tree.size() << std::endl;
	tree.insert(ft::make_pair(1,1));
	tree.insert(ft::make_pair(2,2));
	tree.remove(2);
	tree.insert(ft::make_pair(10,2));
	tree.insert(ft::make_pair(5,2));
	tree.inOrder();
	tree.clear();
	tree.clear();
	//tree.insert(ft::make_pair(10,2));
	//tree.insert(ft::make_pair(5,2));
	return 0;
}
