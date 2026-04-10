/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:13:22 by strieste          #+#    #+#             */
/*   Updated: 2026/04/10 15:06:16 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>

class PmergeMe
{
	public:
		
	private:
		std::deque<int, int>	_deque;
		std::vector<int, int>	_vector;
};

#endif