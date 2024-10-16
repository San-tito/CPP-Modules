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

PhoneBook::PhoneBook(void) : size(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

inline std::string truncate(std::string str)
{
	return ((str.length() > WIDTH) ? str.substr(0, WIDTH - 1) + "." : str);
}

void PhoneBook::display(void)
{
	std::cout << '|' << std::setw(WIDTH) << "index";
	std::cout << '|' << std::setw(WIDTH) << "first name";
	std::cout << '|' << std::setw(WIDTH) << "last name";
	std::cout << '|' << std::setw(WIDTH) << "nickname";
	std::cout << '|' << '\n';
	for (int i(0); i < size; i++)
	{
		std::cout << '|' << std::setw(WIDTH) << i;
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getFirstName());
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getLastName());
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getNickname());
		std::cout << '|' << '\n';
	}
}

void PhoneBook::search(void)
{
	if (size == 0)
	{
		std::cout << "phonebook is empty\n";
		return ;
	}
	display();
	// getIndex and do: contacts[index].displayDetails();
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
			search();
		else if (line == "EXIT" || std::cin == 0)
			break ;
		std::cin.clear();
	} while (true);
	return (std::cin.fail() && std::cin.eof() == 0);
}
