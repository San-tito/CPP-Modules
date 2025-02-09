/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/09 18:38:06 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments.\n";
		return (1);
	}
	try
	{
		::RPN rpn;
		std::cout << rpn.calculate(argv[1]) << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
