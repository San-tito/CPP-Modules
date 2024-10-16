/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/16 20:00:16 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

inline std::string truncate(std::string str)
{
	return ((str.length() > 10) ? str.substr(0, 9).replace(9, 10, ".") : str);
}

void PhoneBook::display(void)
{
	std::cout << '|' << std::setw(10) << "index";
	std::cout << '|' << std::setw(10) << "first name";
	std::cout << '|' << std::setw(10) << "last name";
	std::cout << '|' << std::setw(10) << "nickname";
	std::cout << '|' << '\n';
	for (int i(0); i < MAX; i++)
	{
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << truncate(contacts_[i].getFirstName());
		std::cout << '|' << std::setw(10) << truncate(contacts_[i].getLastName());
		std::cout << '|' << std::setw(10) << truncate(contacts_[i].getNickname());
		std::cout << '|' << '\n';
	}
}

int PhoneBook::commandPrompt(void)
{
	do
	{
		std::cout << "phonebook$ ";
		std::string line;
		std::getline(std::cin, line);
		if (line == "ADD")
			std::cout << "save a new contact" << std::endl;
		else if (line == "SEARCH")
			display();
		else if (line == "EXIT" || std::cin == 0)
			break ;
		std::cin.clear();
	} while (true);
	return (std::cin.fail() && std::cin.eof() == 0);
}
