/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:57:12 by strieste          #+#    #+#             */
/*   Updated: 2026/03/30 13:57:51 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::string	fileName = "data.csv";
	std::string	res;
	std::string	date;
	std::string	price;

	std::ifstream fd(fileName, std::ios::in);
	if (!fd.is_open()) {
		std::cerr << "Error open " << fileName << std::endl;
		return ;
	}
	while (!fd.eof())
	{
		std::getline(fd, res);
		date = res;
		price = res;
		date.erase(date.begin()+10, date.end());
		price.erase(price.begin(), price.begin()+11);
		_container.push_back(date);
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{ return ; }

BitcoinExchange::~BitcoinExchange()
{
	_container.erase(_container.begin(), _container.end());
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this == &copy)
		return (*this);

	return(*this);
}