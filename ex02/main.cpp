/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:13:25 by strieste          #+#    #+#             */
/*   Updated: 2026/04/17 16:15:29 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	try {
		// if (ac < 2)
		// 	throw (std::invalid_argument("Error: Bad input."));
		std::vector<int> set;
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());
		set.push_back(std::rand());

		PmergeMe	vectorSort;
		vectorSort.StartVector(set);
		std::vector<int> set2 = vectorSort.getVector();
		for (int n : set)
			std::cout << n << ", ";
		std::cout << std::endl;
		for (int n : set2)
			std::cout << n << ", ";
		std::cout << std::endl;
		std::cout << set2.size() << ", " << set.size() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Success" << std::endl;
	return (0);
}