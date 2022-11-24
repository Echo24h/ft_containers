/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:11:49 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 05:31:48 by gborne           ###   ########.fr       */
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

void	check( const std::string & test_name, const int & std_value, const int & ft_value, bool isNull = false );

void	check_vec_cont( const std::string & test_name, std::vector<int> & std_cont, ft::vector<int> & ft_cont );

void	check_pair( const std::string & test_name, 
			const std::map<int, int>::iterator & std_value, 
			const ft::map<int, int>::iterator & ft_value, 
			bool isNull = false );

void	check_const_pair( const std::string & test_name, 
			const std::map<int, int>::const_iterator & std_value, 
			const ft::map<int, int>::const_iterator & ft_value, 
			bool isNull = false );

void	check_rconst_pair( const std::string & test_name, 
			const std::map<int, int>::const_reverse_iterator & std_value, 
			const ft::map<int, int>::const_reverse_iterator & ft_value, 
			bool isNull = false );

void	check_pair_char( const std::string & test_name, 
			const std::map<char, int>::iterator & std_value, 
			const ft::map<char, int>::iterator & ft_value, 
			bool isNull = false  );

void	check_pair_it( const std::string & test_name, 
			const std::pair<std::map<int, int>::iterator, bool>  & std_value, 
			const ft::pair<ft::map<int, int>::iterator,bool> & ft_value );

void	check_map_cont( const std::string & test_name,
			std::map<int, int>::iterator std_it, std::map<int, int>::iterator std_ite,
			ft::map<int, int>::iterator ft_it, ft::map<int, int>::iterator ft_ite );

void	print_std_map(std::map<int, int> map);
void	print_ft_map(ft::map<int,int> map);

int	test_vector( void );
int	test_map( void );
int	test_bst( void );

#endif
