/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:11:49 by gborne            #+#    #+#             */
/*   Updated: 2022/11/23 20:44:15 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <exception>
#include <iostream>
#include "../inc/map.hpp"
#include "../inc/vector.hpp"
#include "../inc/map_tree.hpp"
#include "../inc/utils.hpp"
#include <map>
#include <vector>

#define	RED "\033[1;31m"
#define	GREEN "\033[1;32m"
#define	YELLOW "\033[1;33m"
#define	BLUE "\033[1;34m"
#define	MAGENTA "\033[1;35m"
#define	DEF "\033[0m"

// VECTOR

template < typename T >
void	check( const std::string & test_name, const T & std_value, const T & ft_value, bool isNull = false ) {

	std::cout << test_name << ": " << "std=" << std_value << " ft=" << ft_value << " ";
	if (isNull)
		std::cout << YELLOW << "null" << DEF;
	else if (std_value == ft_value)
		std::cout << GREEN << "OK" << DEF;
	else
		std::cout << RED << "KO" << DEF;
	std::cout << std::endl;
	return ;
}

template < typename T >
void	check_vec_cont( const std::string & test_name, std::vector<T> & std_cont, ft::vector<T> & ft_cont ) {

	ft::vector<int>::iterator ft_it = ft_cont.begin();
	std::vector<int>::iterator std_it = std_cont.begin();

	ft::vector<int>::iterator ft_ite = ft_cont.end();
	std::vector<int>::iterator std_ite = std_cont.end();

	std::cout << test_name << ": " << BLUE << "content " << DEF;

	while (ft_it != ft_ite && std_it != std_ite) {
		if (*ft_it != *std_it)
			break ;
		*ft_it++;
		*std_it++;
	}
	if (ft_it != ft_ite || std_it != std_ite)
		std::cout << RED << "KO" << DEF;
	else
		std::cout << GREEN << "OK" << DEF;
	std::cout << std::endl;
	return ;
}

// MAP

/*
template < typename T, typename U >
void	print_map(std::map<T, U> map) {
	for (typename std::map<T, U>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

template < typename T, typename U >
void	print_map(typename ft::map<T,U> map) {
	for (typename ft::map<T,U>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}
*/

template < typename std_map_it = std::map<int, int>::iterator, typename ft_map_it = ft::map<int, int>::iterator >
void	check_pair( const std::string & test_name, const std_map_it & std_value, const ft_map_it & ft_value, bool isNull = false ) {

	std::cout << test_name << ": ";
	std::cout << std_value->first << " => " << std_value->second << " | ";
	std::cout << ft_value->first << " => " << ft_value->second << " ";
	if (isNull)
		std::cout << YELLOW << "null" << DEF;
	else if (std_value->first == ft_value->first && std_value->second == ft_value->second)
		std::cout << GREEN << "OK" << DEF;
	else
		std::cout << RED << "KO" << DEF;
	std::cout << std::endl;
	return ;
}

template < typename std_map_it = std::map<char, int>::iterator, typename ft_map_it = ft::map<char, int>::iterator >
void	check_pair_char( const std::string & test_name, const std_map_it & std_value, const ft_map_it & ft_value, bool isNull = false  ) {

	std::cout << test_name << ": ";
	std::cout << std_value->first << " => " << std_value->second << " | ";
	std::cout << ft_value->first << " => " << ft_value->second << " ";
	if (isNull)
		std::cout << YELLOW << "null" << DEF;
	else if (std_value->first == ft_value->first && std_value->second == ft_value->second)
		std::cout << GREEN << "OK" << DEF;
	else
		std::cout << RED << "KO" << DEF;
	std::cout << std::endl;
	return ;
}

template < typename std_map_it = std::map<int, int>::iterator, typename ft_map_it = ft::map<int, int>::iterator, class std_pair = std::pair<std_map_it, bool> ,class ft_pair = ft::pair<ft_map_it,bool> >
void	check_pair_it( const std::string & test_name, const std_pair & std_value, const ft_pair & ft_value ) {

	std::cout << test_name << ": ";
	std::cout << std_value.first->first << " => " << std_value.first->second << " bool=" <<std_value.second << " | ";
	std::cout << ft_value.first->first << " => " << ft_value.first->second << " bool=" <<ft_value.second;
	if (std_value.first->first == ft_value.first->first
	&& std_value.first->second == ft_value.first->second
	&& std_value.second == ft_value.second)
		std::cout << GREEN << " OK" << DEF;
	else
		std::cout << RED << " KO" << DEF;
	std::cout << std::endl;
	return ;
}

template < typename std_map_it = std::map<int, int>::iterator, typename ft_map_it = ft::map<int, int>::iterator >
void	check_map_cont( const std::string & test_name,
		std_map_it std_it, std_map_it std_ite,
		ft_map_it ft_it, ft_map_it ft_ite ) {

	std::cout << test_name << ": " << BLUE << "content " << DEF;

	while (ft_it != ft_ite && std_it != std_ite) {
		if (ft_it->first != std_it->first || ft_it->second != std_it->second )
			break ;
		ft_it++;
		std_it++;
	}
	if (ft_it != ft_ite || std_it != std_ite)
		std::cout << RED << "KO" << DEF;
	else
		std::cout << GREEN << "OK" << DEF;
	std::cout << std::endl;
	return ;
}

int	test_vector( void );
int	test_map( void );
int	test_bst( void );

#endif
