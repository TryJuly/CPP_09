/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:19:12 by strieste          #+#    #+#             */
/*   Updated: 2026/03/30 13:57:47 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <vector>
# include <string>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();

		BitcoinExchange&	operator=(BitcoinExchange const &copy);

	private:
		std::vector<std::string>	_container;
};

#endif