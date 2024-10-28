/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 08:41:04 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< " I really do!\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	int	index;

	index = (level == "DEBUG") ? 0 : (level == "INFO") ? 1 : (level == "WARNING") ? 2 : (level == "ERROR") ? 3 :
		-1;
	switch (index)
	{
	case 0:
		debug();
		/* fall through */
	case 1:
		info();
		/* fall through */
	case 2:
		warning();
		/* fall through */
	case 3:
		error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
