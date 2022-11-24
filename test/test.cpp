/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:29:40 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 05:39:14 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

// VECTOR

void	check( const std::string & test_name, const int & std_value, const int & ft_value, bool isNull ) {

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

void	check_vec_cont( const std::string & test_name, std::vector<int> & std_cont, ft::vector<int> & ft_cont ) {

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

void	check_pair( const std::string & test_name, 
			const std::map<int, int>::iterator & std_value, 
			const ft::map<int, int>::iterator & ft_value, 
			bool isNull ) {

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

void	check_const_pair( const std::string & test_name, 
			const std::map<int, int>::const_iterator & std_value, 
			const ft::map<int, int>::const_iterator & ft_value, 
			bool isNull ) {

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

void	check_rconst_pair( const std::string & test_name, 
			const std::map<int, int>::const_reverse_iterator & std_value, 
			const ft::map<int, int>::const_reverse_iterator & ft_value, 
			bool isNull ) {

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

void	check_pair_char( const std::string & test_name, 
			const std::map<char, int>::iterator & std_value, 
			const ft::map<char, int>::iterator & ft_value, 
			bool isNull ) {

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

void	check_pair_it( const std::string & test_name, 
			const std::pair<std::map<int, int>::iterator, bool>  & std_value, 
			const ft::pair<ft::map<int, int>::iterator,bool> & ft_value ) {

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

void	check_map_cont( const std::string & test_name,
			std::map<int, int>::iterator std_it, std::map<int, int>::iterator std_ite,
			ft::map<int, int>::iterator ft_it, ft::map<int, int>::iterator ft_ite ) {

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

void	print_std_map(std::map<int, int> map) {
	for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void	print_ft_map(ft::map<int,int> map) {
	for (ft::map<int,int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}