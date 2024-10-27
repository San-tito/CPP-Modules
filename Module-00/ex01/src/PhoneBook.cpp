/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 19:22:10 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : m_count(0)
{
	std::cout << "Welcome to my awesome PhoneBook!\n";
	std::cout << "You can store up to " << MAX_CONTACTS << " contacts\n";
	std::cout << "Available commands: ADD, SEARCH, EXIT\n";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye!\n";
}

inline std::string truncate(std::string str)
{
	return ((str.length() > WIDTH) ? str.substr(0, WIDTH - 1) + "." : str);
}

void PhoneBook::display(void) const
{
	std::cout << '|' << std::setw(WIDTH) << truncate("index");
	std::cout << '|' << std::setw(WIDTH) << truncate("first name");
	std::cout << '|' << std::setw(WIDTH) << truncate("last name");
	std::cout << '|' << std::setw(WIDTH) << truncate("nickname");
	std::cout << '|' << '\n';
	for (int i(0); i < m_count; i++)
	{
		std::cout << '|' << std::setw(WIDTH) << i;
		std::cout << '|' << std::setw(WIDTH) << truncate(m_contacts[i].getFirstName());
		std::cout << '|' << std::setw(WIDTH) << truncate(m_contacts[i].getLastName());
		std::cout << '|' << std::setw(WIDTH) << truncate(m_contacts[i].getNickname());
		std::cout << '|' << '\n';
	}
	std::cout << '\n';
}

int	getIndex(void)
{
	int	index;

	std::cout << " [index]> ";
	std::cin >> index;
	bool fail(std::cin.fail());
	if (std::cin.eof())
		return (-1);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ((fail) ? -1 : index);
}

void PhoneBook::search(void) const
{
	int index;

	if (m_count == 0)
		std::cerr << "phonebook is empty\n";
	else
	{
		display();
		index = getIndex();
		if (0 <= index && index < m_count)
			m_contacts[index].displayDetails();
		else if (std::cin.eof() == 0)
			std::cerr << "invalid index\n";
	}
}

std::string getField(const std::string &field)
{
	std::string input;
	std::cout << " [" << field << "]: ";
	std::getline(std::cin, input);
	if (std::cin.fail())
		return ("");
	if (input.empty())
		std::cerr << field << " cannot be empty\n";
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
	if (m_count == MAX_CONTACTS)
	{
		for (int i(1); i < MAX_CONTACTS; i++)
			m_contacts[i - 1] = m_contacts[i];
		m_contacts[MAX_CONTACTS - 1] = contact;
	}
	else
		m_contacts[m_count++] = contact;
}
