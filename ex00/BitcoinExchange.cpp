/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:57:12 by strieste          #+#    #+#             */
/*   Updated: 2026/04/02 11:21:18 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int	IsValideDate(std::string const &str);

BitcoinExchange::BitcoinExchange()
{
	std::string	fileName = "./data.csv";
	std::string	buff;
	std::string	date;
	std::string	strPrice;
	float		floatPrice;

	std::ifstream fd(fileName.c_str(), std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error: Could not open data file"));
	while (!fd.eof())
	{
		std::getline(fd, buff);
		size_t	pos = buff.find(',');
		date = buff.substr(0, pos);
		strPrice = buff.substr(pos + 1, buff.length());
		floatPrice = std::strtof(strPrice.c_str(), NULL);
		_data[date] = floatPrice;
	}
	fd.close();
	return ;
}

BitcoinExchange::BitcoinExchange(std::string const &fileName)
{
	std::string	buff;
	std::string	date;
	std::string	strPrice;
	float		floatPrice;

	std::ifstream fd(fileName.c_str(), std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error: Could not open data file"));
	while (!fd.eof())
	{
		std::getline(fd, buff);
		size_t	pos = buff.find(',');
		date = buff.substr(0, pos);
		strPrice = buff.substr(pos + 1, buff.length());
		floatPrice = std::strtof(strPrice.c_str(), NULL);
		_data[date] = floatPrice;
	}
	fd.close();
	return ;
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	(*this) = copy;
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	_data.erase(_data.begin(), _data.end());
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this == &copy)
		return (*this);
	if (!_data.empty())
		_data.erase(_data.begin(), _data.end());
	_data = copy._data;
	return(*this);
}

void	BitcoinExchange::getPrice(std::string const &line)
{
	std::string	date;
	std::string	number;
	size_t	pipe;

	pipe = line.find('|');
	if (pipe == std::string::npos) {
		std::cout << "Error: Bad input => " << line << std::endl;
		return ;
	}
	date = line.substr(0, pipe);
	number = line.substr(pipe + 1, line.length());

	if (IsValideDate(date) || IsValideNumber(Price))
	
}

static int	IsValideDate(std::string date)
{
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
