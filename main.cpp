/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:44:08 by gborne            #+#    #+#             */
/*   Updated: 2022/11/17 16:44:59 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.hpp"
#include <cstddef>

size_t	cmds_size(std::string cmds[]) {
	size_t i = 0;
	while (cmds[i] != "end")
		i++;
	return i;
}

bool	isFind(std::string cmds[], std::string cmd) {
	for (size_t i = 0; i < cmds_size(cmds); i++)
		if (cmds[i] == cmd)
			return true;
	return false;
}

int	main(int arg, char **argv) {

	std::string cmds[] = {
		"map",
		"vec",
		"bst",
		"stack",
		"speed",
		"end"
	};

	if (arg != 2 || !isFind(cmds, argv[1])) {
		std::cout << "usage :" << std::endl;
		for (size_t i = 0; i < cmds_size(cmds); i++)
			std::cout << "       ./check " << cmds[i] << std::endl;
	}
	else {
		if (argv[1] == cmds[0])
			test_map();
		else if (argv[1] == cmds[1])
			test_vector();
		else if (argv[1] == cmds[2])
			test_bst();
	}

}
