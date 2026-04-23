/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:13:25 by strieste          #+#    #+#             */
/*   Updated: 2026/04/22 17:34:11 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>
#include <climits>
#include <set>
// #include <sys/time.h>
#include <time.h>
#include <iomanip>

static std::vector<int>	IsValidArgs(int ac, char **av);

int	main(int ac, char **av)
{
	try {
		if (ac < 2)
			throw (std::invalid_argument("Error: Bad input."));

		std::vector<int> set = IsValidArgs(ac, av);
		PmergeMe	vectorSort(set);
		struct timespec	start, end;

		clock_gettime(CLOCK_MONOTONIC, &start);
		vectorSort.StartVector(set);
		clock_gettime(CLOCK_MONOTONIC, &end);
		// double	totalStart = static_cast<double>(start.tv_sec) * 1000000 + static_cast<double>(start.tv_usec);
		// double	totalEnd = static_cast<double>(end.tv_sec) * 1000000 + static_cast<double>(end.tv_usec);
		double	timeVector = ((static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_nsec) - static_cast<double>(start.tv_nsec)) / 1000.0);

		clock_gettime(CLOCK_MONOTONIC, &start);
		vectorSort.StartDeque(set);
		clock_gettime(CLOCK_MONOTONIC, &end);
		// totalStart = static_cast<double>(start.tv_sec) * 100000 + static_cast<double>(start.tv_usec);
		// totalEnd = static_cast<double>(end.tv_sec) * 100000 + static_cast<double>(end.tv_usec);
		double	timeDeque = ((static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec)) * 1000000.0 + (static_cast<double>(end.tv_nsec) - static_cast<double>(start.tv_nsec)) / 1000.0);

		std::vector<int> setSort = vectorSort.getVector();
		std::cout << "Before: ";
		for (size_t	i = 0; i < set.size(); i++)
			std::cout << set[i] << " ";
		std::cout << std::endl;

		std::cout << "After: ";
		for (size_t	i = 0; i < setSort.size(); i++)
			std::cout << setSort[i] << " ";
		std::cout << std::endl;

		std::cout << "Time to process a range of " << set.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(5) << timeVector << " us" << std::endl;
		std::cout << "Time to process a range of " << set.size() << " elements with std::deque<int> : " << std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Success" << std::endl;
	return (0);
}

static std::vector<int>	IsValidArgs(int ac, char **av)
{
	std::vector<int>	stack;
	std::set<int>	checkDouble;
	for (int i = 1; i < ac; i++) {
		if (av[i][0] == '\0')
			throw (std::invalid_argument("Error: Empty argument."));
		errno = 0;
		char	*end = NULL;
		long	res = std::strtol(av[i], &end, 10);
		if (errno == ERANGE || res > INT_MAX) {
			// stack.clear();
			// checkDouble.clear();
			throw (std::invalid_argument("Error: Number out of range."));
		}
		if (*end != '\0') {
			// stack.clear();
			// checkDouble.clear();
			throw (std::invalid_argument("Error: Invalide charaacter in number."));
		}
		if (res <= 0) {
			// stack.clear();
			// checkDouble.clear();
			throw (std::invalid_argument("Error: Not a positiv integer."));
		}
		if (checkDouble.count(res) > 0) {
			// stack.clear();
			// checkDouble.clear();
			throw (std::invalid_argument("Error: Duplicate detected."));
		}
		stack.push_back(static_cast<int>(res));
		checkDouble.insert(static_cast<int>(res));
	}
	// checkDouble.clear();
	return (stack);
}
