/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/09 19:07:31 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &other)
{
	static_cast<void>(other);
}

RPN &RPN::operator=(const RPN &other)
{
	static_cast<void>(other);
	return (*this);
}

RPN::~RPN(void)
{
}

double RPN::calculate(const std::string &expr)
{
	std::stack<double> stack;
	std::istringstream iss(expr);
	std::string token;
	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("syntax error");
			double b(stack.top());
			stack.pop();
			double a(stack.top());
			stack.pop();
			stack.push(process(a, b, Operator(token[0])));
		}
		else
		{
			std::istringstream iss(token);
			double value(0);
			if ((iss >> value) == 0)
				throw std::runtime_error("syntax error");
			stack.push(value);
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("syntax error");
	return (stack.top());
}

bool RPN::isOperator(const std::string &token) const
{
	char c(token[0]);
	return (token.length() == 1 && (c == ADD || c == SUBTRACT || c == MULTIPLY
			|| c == DIVIDE));
}

double RPN::process(double a, double b, Operator op) const
{
	switch (op)
	{
	case ADD:
		return (a + b);
	case SUBTRACT:
		return (a - b);
	case MULTIPLY:
		return (a * b);
	case DIVIDE:
		return (a / b);
	default:
		throw std::runtime_error("syntax error");
	}
}
