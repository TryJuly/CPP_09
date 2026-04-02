/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:43:27 by strieste          #+#    #+#             */
/*   Updated: 2026/03/31 15:20:44 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <climits>

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Error: Could not open file." << std::endl;
		return (1);
	}
	else if (ac > 2) {
		std::cerr << "Error: Too many arguments." << std::endl;
		return (1);
	}

	std::string	inputName =  av[1];
	std::ifstream	fd(inputName, std::ios::in);
	if (!fd.is_open()) {
		std::cerr << "Error: Invalide file name." << std::endl;
		return (1);
	}
	std::string	buff;
	std::string	date;
	
	while (!fd.eof()) {
		getline(fd, buff);
	}

	fd.close();
	return (0);
}

static int	IsValideDate(std::string const &str);

static int	IsValideLine(std::string const &str)
{
	size_t	pos = str.find('|');
	if (pos == std::string::npos) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	if (IsValideDate(str))
		return (1);
	std::string	strPrice = str.substr(pos + 1, str.length());
	errno = 0;
	char	*end;
	long	nbrPrice = std::strtol(strPrice.c_str(), &end, 10);
	if (errno == ERANGE) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	if (nbrPrice < 0 || nbrPrice > 1000) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	return (0);
}

static int	ValideDateRange(long nbrYear, long nbrMonth, long nbrDay);

static int	IsValideDate(std::string const &str)
{
	size_t	pos = str.find('|');
	std::string	date = str.substr(0, pos);
	size_t	posOne = date.find('-');
	size_t	posTwo = date.find(posOne, '-');
	size_t	posThree = date.find(posTwo, '-');

	if (posOne == std::string::npos || posTwo == std::string::npos || posThree == std::string::npos) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	std::string year = date.substr(0, posOne);
	std::string month = date.substr(posOne + 1, posTwo);
	std::string day = date.substr(posTwo + 1, posThree);

	errno = 0;
	char	*end;
	long	nbrYear = std::strtol(year.c_str(), &end, 10);
	if (errno == ERANGE || end != '\0') {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	errno = 0;
	long	nbrMonth = std::strtol(month.c_str(), &end, 10);
	if (errno == ERANGE || end != '\0') {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	errno = 0;
	long	nbrDay = std::strtol(day.c_str(), &end, 10);
	if (errno == ERANGE || end != '\0') {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	if (ValideDateRange(nbrYear, nbrMonth, nbrDay)) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return (1);
	}
	return (0);
}

static int	ValideDateRange(long nbrYear, long nbrMonth, long nbrDay)
{
	if (nbrYear <= 0 || nbrMonth <= 0 || nbrDay <= 0)
		return (1);
	if (nbrYear < 2009 || nbrYear > 2026)
		return (1);
	if (nbrMonth > 12 || nbrDay > 31)
		return (1);
	if (nbrMonth == 2 && nbrDay > 29)
		return (1);
	return (0);
}
