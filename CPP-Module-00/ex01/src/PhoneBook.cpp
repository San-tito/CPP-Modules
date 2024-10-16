/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/09/10 18:58:42 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

int PhoneBook::commandPrompt(void)
{
	while (true)
	{
		std::cout << "phonebook$ ";
		std::string line;
		std::getline(std::cin, line);
		if (line == "ADD")
			std::cout << "save a new contact" << '\n';
		else if (line == "SEARCH")
			std::cout << "display a specific contact" << '\n';
		else if (line == "EXIT" || std::cin == 0)
			break ;
		else if (line.empty() == 0)
			std::cout << "command not found: " << line << '\n';
		std::cin.clear();
	}
	return (std::cin.fail() && std::cin.eof() == 0);
}
