/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:50 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 19:26:05 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : m_first_name(""), m_last_name(""), m_nickname(""),
	m_phone(""), m_secret("")
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
	return (m_first_name);
}

void Contact::setFirstName(std::string first_name)
{
	m_first_name = first_name;
}

std::string Contact::getLastName(void) const
{
	return (m_last_name);
}

void Contact::setLastName(std::string last_name)
{
	m_last_name = last_name;
}

std::string Contact::getNickname(void) const
{
	return (m_nickname);
}

void Contact::setNickname(std::string nickname)
{
	m_nickname = nickname;
}

void Contact::setPhone(std::string phone)
{
	m_phone = phone;
}

void Contact::setSecret(std::string secret)
{
	m_secret = secret;
}

void Contact::displayDetails(void) const
{
	std::cout << "First Name: " << m_first_name << '\n';
	std::cout << "Last Name: " << m_last_name << '\n';
	std::cout << "Nickname: " << m_nickname << '\n';
	std::cout << "Phone Number: " << m_phone << '\n';
	std::cout << "Darkest Secret: " << m_secret << '\n';
}
