/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:06 by gborne            #+#    #+#             */
/*   Updated: 2022/11/22 12:39:42 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_vector( void ) {

	ft::vector<int>		ft_vector;
	std::vector<int>	std_vector;

	for (int i = 10; i < 20; i++) {
		srand(time(NULL));
		int	n = random() % 10;
		std_vector.push_back(n);
		ft_vector.push_back(n);
	}

	check_vec_cont("push_back()", std_vector, ft_vector);

	std::cout << YELLOW << "CONSTRUCTOR TEST" << DEF << std::endl;

	{
		ft::vector<int>		ft_c_vec(10, 15);
		std::vector<int>	std_c_vec(10, 15);
		check_vec_cont("vec(10, 15)", std_c_vec, ft_c_vec);
		check("capacity()", std_c_vec.capacity(), ft_c_vec.capacity());
		check("size()", std_c_vec.size(), ft_c_vec.size());

		ft::vector<int>		ft_c_vec2(ft_c_vec.begin(), ft_c_vec.end());
		std::vector<int>	std_c_vec2(std_c_vec.begin(), std_c_vec.end());
		check_vec_cont("vec(begin(), end())", std_c_vec2, ft_c_vec2);
		check("capacity()", std_c_vec2.capacity(), ft_c_vec2.capacity());
		check("size()", std_c_vec2.size(), ft_c_vec2.size());

		ft::vector<int>		ft_c_vec3(ft_c_vec2);
		std::vector<int>	std_c_vec3(std_c_vec2);
		check_vec_cont("vec(vec)", std_c_vec3, ft_c_vec3);
		check("capacity()", std_c_vec3.capacity(), ft_c_vec3.capacity());
		check("size()", std_c_vec3.size(), ft_c_vec3.size());
	}

	std::cout << YELLOW << "ITERATORS TEST" << DEF << std::endl;

	std::cout << MAGENTA << "begin()" << DEF << std::endl;

	ft::vector<int>::iterator ft_it = ft_vector.begin();
	std::vector<int>::iterator std_it = std_vector.begin();

	check("*it/*begin()", *std_it, *ft_it);
	check("*end()", *std_vector.end(), *ft_vector.end());
	check("*it++", *std_it++, *ft_it++);
	check("*++it", *++std_it, *++ft_it);
	check("*it--", *std_it--, *ft_it--);
	check("*--it", *--std_it, *--ft_it);

	std::cout << MAGENTA << "cbegin()" << DEF << std::endl;

	ft::vector<int>::const_iterator ft_cit = ft_vector.cbegin();
	std::vector<int>::const_iterator std_cit = std_vector.cbegin();

	check("*cit++", *std_cit++, *ft_cit++);
	check("*++cit", *++std_cit, *++ft_cit);
	check("*cit--", *std_cit--, *ft_cit--);
	check("*--cit", *--std_cit, *--ft_cit);

	std::cout << MAGENTA << "rbegin()" << DEF << std::endl;

	ft::vector<int>::reverse_iterator ft_rit = ft_vector.rbegin();
	std::vector<int>::reverse_iterator std_rit = std_vector.rbegin();

	check("*rit", *std_rit, *ft_rit);
	check("*rend()", *std_vector.rend(), *ft_vector.rend());
	check("*rbegin()", *std_vector.rbegin(), *ft_vector.rbegin());
	check("rit[5]", std_rit[5], ft_rit[5]);
	check("rit[8]", std_rit[8], ft_rit[8]);
	check("rit[2]", std_rit[2], ft_rit[2]);
	check("*rit++", *std_rit++, *ft_rit++);
	check("*++rit", *++std_rit, *++ft_rit);
	check("*rit", *std_rit, *ft_rit);
	check("*rit += 2", *std_rit += 2, *ft_rit += 2);
	check("*rit -= 2", *std_rit -= 2, *ft_rit -= 2);
	check("*rit", *std_rit, *ft_rit);
	check("*rit.base()", *std_rit.base(), *ft_rit.base());
	check("*rit >= *++rit", *std_rit >= *++std_rit, *ft_rit >= *++ft_rit);
	check("*rit", *std_rit, *ft_rit);
	check("*rit - 3", *std_rit - 3, *ft_rit - 3);
	check("*rit + 3", *std_rit + 3, *ft_rit + 3);
	check("*rit--", *std_rit--, *ft_rit--);
	check("*--rit", *--std_rit, *--ft_rit);
	check("*rit.base()", *std_rit.base(), *ft_rit.base());
	check("*rit", *std_rit, *ft_rit);
	check("*rit == 5", *std_rit == 5, *ft_rit == 5);
	check("*rit != 5", *std_rit != 5, *ft_rit != 5);
	check("*rit < 5", *std_rit < 5, *ft_rit < 5);
	check("*rit <= 5", *std_rit <= 5, *ft_rit <= 5);
	check("*rit > 5", *std_rit > 5, *ft_rit > 5);
	check("*rit >= 5", *std_rit >= 5, *ft_rit >= 5);

	std::cout << MAGENTA << "crbegin()" << DEF << std::endl;

	ft::vector<int>::const_reverse_iterator ft_crit = ft_vector.crbegin();
	std::vector<int>::const_reverse_iterator std_crit = std_vector.crbegin();

	check("*crit++", *std_crit++, *ft_crit++);
	check("*++crit", *++std_crit, *++ft_crit);
	check("*crit--", *std_crit--, *ft_crit--);
	check("*--crit", *--std_crit, *--ft_crit);
	check("crit", *std_crit, *ft_crit);

	std::cout << YELLOW << "CAPACITY TEST" << DEF << std::endl;

	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	std_vector.resize(5);		ft_vector.resize(5);
	check_vec_cont("resize(5)", std_vector, ft_vector);
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	std_vector.resize(10, 8);	ft_vector.resize(10, 8);
	check_vec_cont("resize(10, 8)", std_vector, ft_vector);
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	std_vector.resize(12, 10);		ft_vector.resize(12, 10);
	check_vec_cont("resize(12, 10)", std_vector, ft_vector);
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	std_vector.resize(5);		ft_vector.resize(5);
	check_vec_cont("resize(5)", std_vector, ft_vector);

	for (int i = 10; i < 30; i++) {
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	check("empty()", std_vector.empty(), ft_vector.empty());
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	std_vector.reserve(75); ft_vector.reserve(75);
	check("reserve(75)", std_vector.capacity(), ft_vector.capacity());
	check("size()", std_vector.size(), ft_vector.size());
	check("max_size()", std_vector.max_size(), ft_vector.max_size());
	//std_vector.shrink_to_fit(); ft_vector.shrink_to_fit();
	std::cout << RED << "std::vector::shrink_to_fit() doesn't exist" << DEF << std::endl;
	//check("shrink_to_fit()", std_vector.capacity(), ft_vector.capacity());
	check_vec_cont("check content", std_vector, ft_vector);

	std::cout << YELLOW << "ELEMENT ACCESS TEST" << DEF << std::endl;

	try {
		check("[3]", std_vector[3], ft_vector[3]);
		check("at(1)", std_vector.at(1), ft_vector.at(1));
		check("front()", std_vector.front(), ft_vector.front());
		check("back()", std_vector.back(), ft_vector.back());
		check("*data()", *std_vector.data(), *ft_vector.data());
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "MODIFIERS TEST" << DEF << std::endl;

	ft::vector<int>		new_ft_vector;
	std::vector<int>	new_std_vector;

	std::cout << MAGENTA << "assign()" << DEF << std::endl;

	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	check("size()", std_vector.size(), ft_vector.size());

	new_std_vector.assign(std_vector.begin(), std_vector.end());
	new_ft_vector.assign(ft_vector.begin(), ft_vector.end());

	check_vec_cont("assign(vector.begin(), vector.end())", new_std_vector, new_ft_vector);
	check("[3]", new_std_vector[3], new_ft_vector[3]);
	std_vector.clear();	ft_vector.clear();
	check("clear()", std_vector.empty(), ft_vector.empty());
	std_vector.assign(99, 1);	ft_vector.assign(99, 1);
	check_vec_cont("assign(99, 1)", std_vector, ft_vector);
	check("size()", std_vector.size(), ft_vector.size());

	check("capacity()", std_vector.capacity(), ft_vector.capacity());

	std::cout << MAGENTA << "insert()" << DEF << std::endl;


	//iterator	insert( iterator position, const value_type& val )

	check("insert(begin() + 10, 3)", *std_vector.insert(std_vector.begin() + 10, 3), *ft_vector.insert(ft_vector.begin() + 10, 3));

	// void	insert (iterator position, size_type n, const value_type& val);

	std_vector.insert(std_vector.begin(), 3, 5);
	ft_vector.insert(ft_vector.begin(), 3, 5);

	// void insert (iterator position, InputIterator first, InputIterator last);

	std_vector.insert(std_vector.begin(), new_std_vector.begin(), new_std_vector.end());
	ft_vector.insert(ft_vector.begin(), new_ft_vector.begin(), new_ft_vector.end());

	std_vector.insert(std_vector.begin() + 5, new_std_vector.begin(), new_std_vector.end());
	ft_vector.insert(ft_vector.begin() + 5, new_ft_vector.begin(), new_ft_vector.end());

	std_vector.insert(std_vector.end(), new_std_vector.begin(), new_std_vector.end());
	ft_vector.insert(ft_vector.end(), new_ft_vector.begin(), new_ft_vector.end());

	check("size()", std_vector.size(), ft_vector.size());
	check_vec_cont("insert()", std_vector, ft_vector);
	check("capacity()", std_vector.capacity(), ft_vector.capacity());

	std::cout << MAGENTA << "erase()" << DEF << std::endl;

	check("erase(begin() + 10)", *std_vector.erase(std_vector.begin() + 10), *ft_vector.erase(ft_vector.begin() + 10));
	check("erase(begin())", *std_vector.erase(std_vector.begin()), *ft_vector.erase(ft_vector.begin()));
	check("erase(end() - 1)", *std_vector.erase(std_vector.end() - 1), *ft_vector.erase(ft_vector.end() - 1));
	check_vec_cont("erase()", std_vector, ft_vector);
	check("erase(begin(), begin() + 10)", *std_vector.erase(std_vector.begin(), std_vector.begin() + 10), *ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 10));
	check("erase(begin() + 5, begin() + 10)", *std_vector.erase(std_vector.begin() + 5, std_vector.begin() + 10), *ft_vector.erase(ft_vector.begin() + 5, ft_vector.begin() + 10));
	check("erase(end() - 5, end())", *std_vector.erase(std_vector.end() - 5, std_vector.end()), *ft_vector.erase(ft_vector.end() - 5, ft_vector.end()));
	check_vec_cont("erase()", std_vector, ft_vector);
	check("size()", std_vector.size(), ft_vector.size());
	check("capacity()", std_vector.capacity(), ft_vector.capacity());

	std::cout << MAGENTA << "swap()" << DEF << std::endl;

	std_vector.swap(new_std_vector); ft_vector.swap(new_ft_vector);
	check_vec_cont("swap()", std_vector, ft_vector);
	check("size()", std_vector.size(), ft_vector.size());
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	check("capacity(new)", new_std_vector.capacity(), new_ft_vector.capacity());

	std_vector.swap(new_std_vector); ft_vector.swap(new_ft_vector);
	check_vec_cont("swap()", std_vector, ft_vector);
	check("size()", std_vector.size(), ft_vector.size());
	check("capacity()", std_vector.capacity(), ft_vector.capacity());
	check("capacity(new)", new_std_vector.capacity(), new_ft_vector.capacity());

	std::cout << YELLOW << "RELATIONAL OPERATORS TEST" << DEF << std::endl;

	new_ft_vector = ft_vector;
	new_std_vector = std_vector;

	check("==", std_vector == new_std_vector, ft_vector == new_ft_vector);
	check("!=", std_vector != new_std_vector, ft_vector != new_ft_vector);
	check("<", std_vector < new_std_vector, ft_vector < new_ft_vector);
	check("<=", std_vector <= new_std_vector, ft_vector <= new_ft_vector);
	check(">", std_vector > new_std_vector, ft_vector > new_ft_vector);
	check(">=", std_vector >= new_std_vector, ft_vector >= new_ft_vector);
	check("erase(end() - 5, end())", *std_vector.erase(std_vector.end() - 5, std_vector.end()), *ft_vector.erase(ft_vector.end() - 5, ft_vector.end()));
	check("==", std_vector == new_std_vector, ft_vector == new_ft_vector);
	check("!=", std_vector != new_std_vector, ft_vector != new_ft_vector);
	check("<", std_vector < new_std_vector, ft_vector < new_ft_vector);
	check("<=", std_vector <= new_std_vector, ft_vector <= new_ft_vector);
	check(">", std_vector > new_std_vector, ft_vector > new_ft_vector);
	check(">=", std_vector >= new_std_vector, ft_vector >= new_ft_vector);

	return 0;
}
