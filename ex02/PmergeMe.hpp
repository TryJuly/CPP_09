/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:13:22 by strieste          #+#    #+#             */
/*   Updated: 2026/04/17 10:25:34 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe&	operator=(PmergeMe const &copy);
		std::vector<int>	getVector() const;

		// void	StartDeque(std::vector<int> tab);
		void	StartVector(std::vector<int> tab);
	private:
		std::deque<int>	_deque;
		std::deque<std::pair<int,int> >	_dequePairs;
		std::vector<int>	_vector;
		std::vector<std::pair<int, int> >	_vectorPairs;
		int	_last;
		bool	_hasLast;
};

#endif
