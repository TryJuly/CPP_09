/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:54:51 by strieste          #+#    #+#             */
/*   Updated: 2026/04/09 15:07:22 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>
# include <iostream>

class RPN
{
	public:
		RPN();
		RPN(RPN const &copy);
		~RPN();

		RPN&	operator=(RPN const &copy);
		void	getResult(std::string const &str);

	private:
		std::stack<float>	_stack;
};

#endif