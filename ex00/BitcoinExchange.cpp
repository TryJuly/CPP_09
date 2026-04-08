/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:57:12 by strieste          #+#    #+#             */
/*   Updated: 2026/04/08 18:25:17 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	IsValideDate(std::string date);
static void	IsValideNumber(std::string number);
static int	ValideDateRange(long nbrYear, long nbrMonth, long nbrDay);

BitcoinExchange::BitcoinExchange()
{
	std::string	fileName = "./data.csv";
	std::string	buff;
	std::string	date;
	std::string	strPrice;
	float		floatPrice;

	std::ifstream fd(fileName.c_str(), std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error: Could not open data file."));
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
	double		doublePrice;

	std::ifstream fd(fileName.c_str(), std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error: Could not open data file."));
	while (!fd.eof())
	{
		std::getline(fd, buff);
		size_t	pos = buff.find(',');
		date = buff.substr(0, pos);
		strPrice = buff.substr(pos + 1, buff.length());
		doublePrice = std::strtod(strPrice.c_str(), NULL);
		_data[date] = doublePrice;
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
	date = line.substr(0, pipe - 1);
	number = line.substr(pipe + 1, line.length());
	try {
		IsValideDate(date);
		IsValideNumber(number);
	}
	catch (std::exception& e) {
		std::cout << e.what() << line << std::endl;
		return ;
	}
	double	doubleNumber = std::strtod(number.c_str(), NULL);
	std::map<std::string, double>::iterator	itLow;
	itLow = _data.lower_bound(date);
	// std::cout << std::endl;
	if (itLow->first != date && itLow != _data.begin())
		itLow--;
	// std::cout << "DEBUG INPUT:" << date << ": :" << floatNumber << ":" << std::endl;
	// std::cout << "DEBUG:" << itLow->first << ": :" << itLow->second << std::endl;
	// float val = static_cast<float>(itLow->second);
	double result = doubleNumber * static_cast<double>(itLow->second);
	// std::cout << "DEBUG::" << date << " => " << floatNumber << " = " << result << std::endl;
	std::cout << date << " => " << doubleNumber << " = "  << std::fixed << std::setprecision(2) << result << std::endl;
	// std::cout << "DEBUG:" << val << std::endl;
	// std::cout << std::endl;
}

static void	IsValideNumber(std::string number)
{
	errno = 0;
	char	*end;
	double	doubleNumber = std::strtod(number.c_str(), &end);

	if (errno == ERANGE || *end != '\0')
		throw (std::invalid_argument("Error: Bad input => "));
	if (doubleNumber < 0)
		throw (std::invalid_argument("Error: Not a positive number => "));
	if (doubleNumber >= 1000)
		throw (std::invalid_argument("Error: Too large number => "));
	return ;
}

static void	IsValideDate(std::string date)
{
	for (size_t i = 0; i < date.length(); i++)
		if (!std::isdigit(date[i]) && date[i] != '-') {
			std::cout << "DEBUG::" << date << ":" << std::endl;
			throw (std::invalid_argument("Error: Bad input => "));
		}

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	errno = 0;
	char	*end;
	long	nbrYear = std::strtol(year.c_str(), &end, 10);
	if (errno == ERANGE || *end != '\0')
		throw (std::invalid_argument("Error: Bad input => "));
	errno = 0;
	long	nbrMonth = std::strtol(month.c_str(), &end, 10);
	if (errno == ERANGE || *end != '\0')
		throw (std::invalid_argument("Error: Bad input => "));
	errno = 0;
	long	nbrDay = std::strtol(day.c_str(), &end, 10);
	if (errno == ERANGE || *end != '\0')
		throw (std::invalid_argument("Error: Bad input => "));
	if (ValideDateRange(nbrYear, nbrMonth, nbrDay))
		throw (std::invalid_argument("Error: Bad input => "));
	return ;
}

static int	ValideDateRange(long nbrYear, long nbrMonth, long nbrDay)
{
	if (nbrYear <= 0 || nbrMonth <= 0 || nbrDay <= 0)
		return (1);
	if (nbrMonth > 12 || nbrDay > 31)
		return (1);
	if (nbrMonth == 4 || nbrMonth == 6 || nbrMonth == 9 || nbrMonth == 11) {
		if (nbrDay > 30)
			return (1);
	}
	if (nbrYear % 4 == 0 && nbrYear % 100 != 0) {
		if (nbrMonth == 2 && nbrDay > 29)
			return (1);
	}
	else if (nbrYear % 4 != 0) {
		if (nbrMonth == 2 && nbrDay > 28)
			return (1);
	}
	return (0);
}
