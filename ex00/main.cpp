/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:43:27 by strieste          #+#    #+#             */
/*   Updated: 2026/04/08 14:19:23 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <climits>

int	main(int ac, char **av)
{
	try {
		if (ac < 2)
			throw (std::invalid_argument("Error: Could not open file."));
		else if (ac > 2)
			throw (std::invalid_argument("Error: Too many arguments."));

		std::string	buff;
		BitcoinExchange	prog;

		std::ifstream	fd(av[1], std::ios::in);
		if (!fd.is_open())
			throw (std::invalid_argument("Error: Open input file."));
		int i = 0;
		while (!fd.eof()) {
			std::getline(fd, buff);
			if (i == 0 && buff == "date | value") {
				buff.clear();
				continue ;
				i++;
			}
			i++;
			if (buff.empty())
				continue ;
			prog.getPrice(buff);
			buff.clear();
		}
		fd.close();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return (0);
}
