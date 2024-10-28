/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 08:36:04 by santito          ###   ########.fr       */
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
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i(0); i < 4; i++)
		(level == levels[i]) ? (this->*functions[i])() : static_cast<void>(0);
}
