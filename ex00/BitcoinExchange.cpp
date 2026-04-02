/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:57:12 by strieste          #+#    #+#             */
/*   Updated: 2026/03/31 12:08:30 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string	fileName = "data.csv";
	std::string	buff;
	std::string	date;
	std::string	strPrice;
	float		floatPrice;

	std::ifstream fd(fileName, std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error open data file"));
	while (!fd.eof())
	{
		std::getline(fd, buff);
		size_t	pos = buff.find(',');
		date = buff.substr(0, pos);
		strPrice = buff.substr(pos + 1, buff.length());
		floatPrice = strtof(strPrice.c_str(), NULL);
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

	std::ifstream fd(fileName, std::ios::in);
	if (!fd.is_open())
		throw (std::invalid_argument("Error open data file"));
	while (!fd.eof())
	{
		std::getline(fd, buff);
		size_t	pos = buff.find(',');
		date = buff.substr(0, pos);
		strPrice = buff.substr(pos + 1, buff.length());
		floatPrice = strtof(strPrice.c_str(), NULL);
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