/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:43:19 by strieste          #+#    #+#             */
/*   Updated: 2026/04/09 15:07:55 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	SetOperator(char c);

RPN::RPN()
{ return ; }

RPN::RPN(RPN const &copy)
{
	(*this) = copy;
	return ;
}

RPN::~RPN()
{
	while (!_stack.empty())
		_stack.pop();
	return ;
}

RPN&	RPN::operator=(RPN const &copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

void	RPN::getResult(std::string const &str)
{
	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else if (SetOperator(str[i]) && _stack.size() > 1) {
			float	valueOne = _stack.top();
			_stack.pop();
			float	valueTwo = _stack.top();
			_stack.pop();
			float	res = 0;
			if (str[i] == '+')
				res = valueTwo + valueOne;
			else if (str[i] == '-')
				res = valueTwo - valueOne;
			else if (str[i] == '/')
				res = valueTwo / valueOne;
			else if (str[i] == '*')
				res = valueTwo * valueOne;
			_stack.push(res);
		}
		else if (SetOperator(str[i]))
			throw (std::invalid_argument("Error: Invalde input."));
	}
	if (_stack.size() > 1)
		throw (std::invalid_argument("Error: Invalde input."));
	std::cout << _stack.top() << std::endl;
	return ;
}

static int	SetOperator(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == '*')
		return (1);
	if (c == '/')
		return (1);
	return (0);
}
