/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:19:12 by strieste          #+#    #+#             */
/*   Updated: 2026/04/07 11:21:36 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <cstdlib>
# include <iostream>
// # include <iostream>
// # include <algorithm>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &fileName);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();

		BitcoinExchange&	operator=(BitcoinExchange const &copy);

		void	getPrice(std::string const &line);

	private:
		std::map<std::string, float>	_data;
};

#endif