/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:06 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 02:23:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	test_map( void ) {

	ft::map<int, int>	ft_map;
	std::map<int, int>	std_map;

	typedef std::pair<int, int> std_pair;
	typedef ft::pair<int, int> ft_pair;

	typedef ft::map<int, int>::iterator ft_it;
	typedef std::map<int, int>::iterator std_it;

	std::cout << YELLOW << "CAPACITY TEST" << DEF << std::endl;

	check("size()", std_map.size(), ft_map.size());
	check("empty()", std_map.empty(), ft_map.empty());
	check("max_size()", std_map.max_size(), ft_map.max_size(), true);

	std_map.insert(std_pair(30, 10));
	ft_map.insert(ft_pair(30, 10));

	check("size()", std_map.size(), ft_map.size());
	check("empty()", std_map.empty(), ft_map.empty());

	std_map.clear(), ft_map.clear();

	check("empty()", std_map.empty(), ft_map.empty());
	check("size()", std_map.size(), ft_map.size());

	std_map.insert(std_pair(30, 10));
	ft_map.insert(ft_pair(30, 10));

	for (int i = 10; i < 50; i++) {
		if (i % 10 == 0) {
			std_map.insert(std_pair(i, i));
			ft_map.insert(ft_pair(i, i));
		}
	}

	for (int i = 10; i < 50; i++) {
		if (i % 5 == 0) {
			std_map.insert(std_pair(i, i));
			ft_map.insert(ft_pair(i, i));
		}
	}

	for (int i = 10; i < 50; i++) {
		std_map.insert(std_pair(i, i));
		ft_map.insert(ft_pair(i, i));
	}

	check("size()", std_map.size(), ft_map.size());
	check("empty()", std_map.empty(), ft_map.empty());

	check_map_cont("insert() (x40)", std_map.begin(), std_map.end(), ft_map.begin(), ft_map.end());
	check("size()", std_map.size(), ft_map.size());

	std::cout << YELLOW << "CANONICAL TEST" << DEF << std::endl;

	{
		ft::map<int, int>	new_ft_map;
		std::map<int, int>	new_std_map;

		new_ft_map = ft_map;
		new_std_map = std_map;

		check_map_cont("operator=()", new_std_map.begin(), new_std_map.end(), new_ft_map.begin(), new_ft_map.end());
		check("size()", std_map.size(), ft_map.size());
	}

	{
		ft::map<int, int>	new_ft_map(ft_map);
		std::map<int, int>	new_std_map(std_map);

		check_map_cont("newMap(map)", new_std_map.begin(), new_std_map.end(), new_ft_map.begin(), new_ft_map.end());
		check("size()", std_map.size(), ft_map.size());
	}

	{
		ft::map<int, int>	new_ft_map(ft_map.begin(), ft_map.end());
		std::map<int, int>	new_std_map(std_map.begin(), std_map.end());

		check_map_cont("map(Iterators)", new_std_map.begin(), new_std_map.end(), new_ft_map.begin(), new_ft_map.end());
		check("size()", std_map.size(), ft_map.size());
	}

	std::cout << YELLOW << "ITERATORS TEST" << DEF << std::endl;

	{

		std::cout << MAGENTA << "begin()/end()" << DEF << std::endl;

		{

			ft_it	ftIt = ft_map.begin();
			std_it	stdIt = std_map.begin();
			ft_it	ftIte = ft_map.end();
			std_it	stdIte = std_map.end();

			// it

			check_pair("it", stdIt, ftIt);
			check_pair("++it", ++stdIt, ++ftIt);
			check_pair("++it", ++stdIt, ++ftIt);
			for (int i = 0; i < 30; i++)
				stdIt++, ftIt++;
			check_pair("it++ (x30)", stdIt, ftIt);
			for (int i = 0; i < 30; i++)
				stdIt--, ftIt--;
			check_pair("it-- (x30)", stdIt, ftIt);

			// Test for Ubuntu, C++11
			
			/*for (int i = 0; i < 60; i++)
				stdIt++, ftIt++;
			check_pair("it++ (x60)", stdIt, ftIt, true);
			for (int i = 0; i < 60; i++)
				stdIt--, ftIt--;
			check_pair("it-- (x60)", stdIt, ftIt);*/

			//ite

			//check_pair("ite", stdIte, ftIte, true);
			check_pair("--ite", --stdIte, --ftIte);
			check_pair("--ite", --stdIte, --ftIte);
			for (int i = 0; i < 30; i++)
				stdIte--, ftIte--;
			check_pair("ite-- (x30)", stdIte, ftIte);
			for (int i = 0; i < 30; i++)
				stdIte++, ftIte++;
			check_pair("ite++ (x30)", stdIte, ftIte);

			// Test for Ubuntu, C++11

			/*for (int i = 0; i < 60; i++)
				stdIte--, ftIte--;
			check_pair("ite-- (x60)", stdIte, ftIte);
			for (int i = 0; i < 60; i++)
				stdIte++, ftIte++;
			check_pair("ite++ (x60)", stdIte, ftIte);*/
			check_pair("++ite", ++stdIte, ++ftIte);
			//check_pair("++ite", ++stdIte, ++ftIte);
			//check_pair("++ite", ++stdIte, ++ftIte, true);
			//check_pair("++ite", ++stdIte, ++ftIte);
			check_pair("--ite", --stdIte, --ftIte);
			check_pair("--ite", --stdIte, --ftIte);
			check_pair("--ite", --stdIte, --ftIte);


			check("it == begin()", stdIt == std_map.begin(), ftIt == ft_map.begin());
			check("it != begin()", stdIt != std_map.begin(), ftIt != ft_map.begin());
		}

		std::cout << MAGENTA << "cbegin()" << DEF << std::endl;

		{
			ft::map<int,int>::const_iterator	ftCit = ft_map.cbegin();
			std::map<int,int>::const_iterator	stdCit = std_map.cbegin();

			// TEST CONST_ITERATOR
			//stdCit->second = 100;
			//ftCit->second = 100;
			check_const_pair("cit", stdCit, ftCit);
			check_const_pair("++cit", ++stdCit, ++ftCit);

		}

		std::cout << MAGENTA << "crbegin()" << DEF << std::endl;

		{

			ft::map<int,int>::const_reverse_iterator	ftRit = ft_map.crbegin();
			std::map<int,int>::const_reverse_iterator	stdRit = std_map.crbegin();
			ft::map<int,int>::const_reverse_iterator	ftRite = ft_map.crend();
			std::map<int,int>::const_reverse_iterator	stdRite = std_map.crend();

			// it

			check_rconst_pair("crit", stdRit, ftRit);
			check_rconst_pair("++crit", ++stdRit, ++ftRit);
			check_rconst_pair("++crit", ++stdRit, ++ftRit);
			for (int i = 0; i < 30; i++)
				stdRit++, ftRit++;
			check_rconst_pair("crit++ (x30)", stdRit, ftRit);
			for (int i = 0; i < 30; i++)
				stdRit--, ftRit--;
			check_rconst_pair("crit-- (x30)", stdRit, ftRit);

			// Test for Ubuntu, C++11

			/*for (int i = 0; i < 60; i++)
				stdRit++, ftRit++;
			check_rconst_pair("crit++ (x60)", stdRit, ftRit);
			for (int i = 0; i < 60; i++)
				stdRit--, ftRit--;
			check_rconst_pair("crit-- (60)", stdRit, ftRit);*/

			
			check_rconst_pair("--crit", --stdRit, --ftRit);
			check_rconst_pair("--crit", --stdRit, --ftRit);
			//check_rconst_pair("--crit", --stdRit, --ftRit);
			//check_rconst_pair("--crit", --stdRit, --ftRit);
			check_rconst_pair("++crit", ++stdRit, ++ftRit);
			check_rconst_pair("++crit", ++stdRit, ++ftRit);
			check_rconst_pair("++crit", ++stdRit, ++ftRit);

			//ite

			//check_rconst_pair("crite", stdRite, ftRite, true);
			check_rconst_pair("--crite", --stdRite, --ftRite);
			check_rconst_pair("--crite", --stdRite, --ftRite);
			for (int i = 0; i < 30; i++)
				stdRite--, ftRite--;
			check_rconst_pair("crite-- (x30)", stdRite, ftRite);
			for (int i = 0; i < 30; i++)
				stdRite++, ftRite++;
			check_rconst_pair("crite++ (x30)", stdRite, ftRite);

			// Test for Ubuntu, C++11

			/*for (int i = 0; i < 60; i++)
				stdRite--, ftRite--;
			check_rconst_pair("crite-- (x60)", stdRite, ftRite);
			for (int i = 0; i < 60; i++)
				stdRite++, ftRite++;
			check_rconst_pair("crite++ (x60)", stdRite, ftRite);*/

			check_rconst_pair("++crite", ++stdRite, ++ftRite);
			check_rconst_pair("--crite", --stdRite, --ftRite);
		}

		std::cout << MAGENTA << "<char>end()" << DEF << std::endl;


		{

			ft::map<char, int>	ft_char_map;
			std::map<char, int>	std_char_map;

			typedef std::pair<char, int> std_pair;
			typedef ft::pair<char, int> ft_pair;

			for (char i = 'A'; i <= 'z'; i++) {
				std_char_map.insert(std_pair(i, 10));
				ft_char_map.insert(ft_pair(i, 10));
			}

			std::cout << "<char>begin(): " << std_char_map.begin()->first << " => " << std_char_map.begin()->second;
			std::cout << " | " << ft_char_map.begin()->first << " => " << ft_char_map.begin()->second;
			std::cout << GREEN << " OK" << DEF << std::endl;


			std::cout << "<char>rbegin(): " << std_char_map.rbegin()->first << " => " << std_char_map.rbegin()->second;
			std::cout << " | " << ft_char_map.rbegin()->first << " => " << ft_char_map.rbegin()->second;
			std::cout << GREEN << " OK" << DEF << std::endl;

			check("<char>size()", std_char_map.size(), ft_char_map.size());
		}

		std::cout << MAGENTA << "<string>begin()" << DEF << std::endl;


		{

			typedef std::string string;

			ft::map<string, int>	ft_char_map;
			std::map<string, int>	std_char_map;

			typedef std::pair<string, int> std_pair;
			typedef ft::pair<string, int> ft_pair;

			std_char_map.insert(std_pair("str1", 10));
			ft_char_map.insert(ft_pair("str1", 10));
			std_char_map.insert(std_pair("str2", 10));
			ft_char_map.insert(ft_pair("str2", 10));
			std_char_map.insert(std_pair("str3", 10));
			ft_char_map.insert(ft_pair("str3", 10));

			std::cout << "<string>begin(): " << std_char_map.begin()->first << " => " << std_char_map.begin()->second;
			std::cout << " | " << ft_char_map.begin()->first << " => " << ft_char_map.begin()->second;
			std::cout << GREEN << " OK" << DEF << std::endl;

			std::cout << "<string>rbegin(): " << std_char_map.rbegin()->first << " => " << std_char_map.rbegin()->second;
			std::cout << " | " << ft_char_map.rbegin()->first << " => " << ft_char_map.rbegin()->second;
			std::cout << GREEN << " OK" << DEF << std::endl;

			check("<string>size()", std_char_map.size(), ft_char_map.size());
		}

	}

	std::cout << YELLOW << "ELEMENTS ACCESS TEST" << DEF << std::endl;

	{
		check("size()", std_map.size(), ft_map.size());
		check("map[20]", std_map[20], ft_map[20]);
		check("map[100]", std_map[100], ft_map[100]);
		check("map[-1]", std_map[-1], ft_map[-1]);
		check("map[0]", std_map[0], ft_map[0]);

		check("at(0)", std_map.at(0), ft_map.at(0));
		check("at(30)", std_map.at(30), ft_map.at(30));
		check("at(-1)", std_map.at(-1), ft_map.at(-1));
		//check("at(-2)", std_map.at(-2), ft_map.at(-2));

		check("size()", std_map.size(), ft_map.size());
		check_map_cont("content: ", std_map.begin(), std_map.end(), ft_map.begin(), ft_map.end());


	}

	std::cout << YELLOW << "MODIFIERS TEST" << DEF << std::endl;

	{
		std::cout << MAGENTA << "insert()" << DEF << std::endl;

		check("size()", std_map.size(), ft_map.size());
		check_pair_it("insert(5,3)", (std_map.insert( std_pair(5, 3) )), (ft_map.insert(ft_pair(5, 3))));
		check_pair_it("insert(5,3)", (std_map.insert( std_pair(5, 3) )), (ft_map.insert(ft_pair(5, 3))));
		check("size()", std_map.size(), ft_map.size());
		check_pair("insert(begin(),pair(10,2))", std_map.insert(std_map.begin(), std_pair(10, 2) ), ft_map.insert(ft_map.begin(), ft_pair(10, 2)));
		check_pair("insert(begin(),pair(1,2))", std_map.insert(std_map.begin(), std_pair(1, 2) ), ft_map.insert(ft_map.begin(), ft_pair(1, 2)));
		check("size()", std_map.size(), ft_map.size());

		ft::map<int, int>	new_ft_map;
		std::map<int, int>	new_std_map;

		new_std_map.insert(++std_map.begin(),--std_map.end());
		new_ft_map.insert(++ft_map.begin(), --ft_map.end());

		check_map_cont("insert(++begin(), --end())", new_std_map.begin(), new_std_map.end(), new_ft_map.begin(), new_ft_map.end());
		check("size()", new_std_map.size(), new_ft_map.size());

		new_std_map.insert(std_map.begin(),std_map.end());
		new_ft_map.insert(ft_map.begin(), ft_map.end());

		check_map_cont("insert(begin(), end())", new_std_map.begin(), new_std_map.end(), new_ft_map.begin(), new_ft_map.end());
		check("size()", new_std_map.size(), new_ft_map.size());

	}

	return 0;
}
