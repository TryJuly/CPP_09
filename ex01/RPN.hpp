/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:54:51 by strieste          #+#    #+#             */
/*   Updated: 2026/04/08 15:43:12 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
	public:
		RPN();
		RPN(std::string const &str);
		RPN(RPN const &copy);
		~RPN();

		RPN&	operator=(RPN const &copy);

	private:
		std::stack<int>	_stack;
};

#endif