/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/09 18:32:06 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>

class RPN
{
  public:
	enum	Operator
	{
		ADD = '+',
		SUBTRACT = '-',
		MULTIPLY = '*',
		DIVIDE = '/'
	};
	RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN(void);

	double calculate(const std::string &expr);

  private:
	bool isOperator(const std::string &token) const;
	double process(double a, double b, Operator op) const;
};

#endif /* RPN_HPP */
