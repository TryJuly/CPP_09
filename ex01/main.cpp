/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:59:39 by strieste          #+#    #+#             */
/*   Updated: 2026/04/09 10:46:12 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

static int	SetOperator(char c);
static void	CheckInput(std::string const &str);

int	main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw (std::invalid_argument("Error: Bad input."));
		CheckInput(av[1]);
		RPN	myReversePolish;

		myReversePolish.getResult(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << "Success" << std::endl;
	return (0);
}

static void	CheckInput(std::string const &str)
{
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]) && SetOperator(str[i]))
			throw (std::invalid_argument("Error: Bad input."));
		if (std::isdigit(str[i]) && str[i + 1] && std::isdigit(str[i + 1]))
			throw (std::invalid_argument("Error: Bad input."));
	}
	return ;
}

static int	SetOperator(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (0);
	if (c == '*')
		return (0);
	if (c == '/')
		return (0);
	if (c == ' ')
		return (0);
	return (1);
}
