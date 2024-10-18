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

PhoneBook::PhoneBook(void) : count(0)
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
	std::cout << '|' << std::setw(WIDTH) << truncate("index");
	std::cout << '|' << std::setw(WIDTH) << truncate("first name");
	std::cout << '|' << std::setw(WIDTH) << truncate("last name");
	std::cout << '|' << std::setw(WIDTH) << truncate("nickname");
	std::cout << '|' << '\n';
	for (int i(0); i < count; i++)
	{
		std::cout << '|' << std::setw(WIDTH) << i;
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getFirstName());
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getLastName());
		std::cout << '|' << std::setw(WIDTH) << truncate(contacts[i].getNickname());
		std::cout << '|' << '\n';
	}
	std::cout << '\n';
}

inline void	ignoreLine(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int	getIndex(void)
{
	int	index;

	std::cout << " [index]> ";
	std::cin >> index;
	bool success(std::cin);
	std::cin.clear();
	ignoreLine();
	return ((success) ? index : -1);
}

void PhoneBook::search(void)
{
	int	index;

	if (count == 0)
	{
		std::cerr << PROGRAM << ": phonebook is empty\n";
		return ;
	}
	display();
	index = getIndex();
	if (index < 0 || index >= count)
		std::cerr << PROGRAM << ": invalid index\n";
	else
		contacts[index].displayDetails();
}

std::string getField(const std::string field)
{
	std::string input;
	std::cout << " [" << field << "]: ";
	std::getline(std::cin, input);
	if (input.empty())
		std::cerr << PROGRAM << ": " << field << " cannot be empty\n";
	return (input);
}

void PhoneBook::add(void)
{
	Contact	contact;

	std::string field;
	field = getField("First Name");
	if (field.empty())
		return ;
	contact.setFirstName(field);
	field = getField("Last Name");
	if (field.empty())
		return ;
	contact.setLastName(field);
	field = getField("Nickname");
	if (field.empty())
		return ;
	contact.setNickname(field);
	field = getField("Phone Number");
	if (field.empty())
		return ;
	contact.setPhone(field);
	field = getField("Darkest Secret");
	if (field.empty())
		return ;
	contact.setSecret(field);
	if (count == MAX)
	{
		for (int i(1); i < MAX; i++)
			contacts[i - 1] = contacts[i];
		contacts[MAX - 1] = contact;
	}
	else
		contacts[count++] = contact;
}

int PhoneBook::commandPrompt(void)
{
	std::string command("");
	do
	{
		if (command == "ADD")
			add();
		else if (command == "SEARCH")
			search();
		else if (command == "EXIT")
			break ;
		std::cout << "$ ";
	} while (std::getline(std::cin, command));
	return (std::cin.fail());
}
