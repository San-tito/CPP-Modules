/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:50 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/16 20:00:48 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : first_name_(""), last_name_(""), nickname_(""),
	phone_(""), secret_("")
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
	return (first_name_);
}

void Contact::setFirstName(std::string first_name)
{
	first_name_ = first_name;
}

std::string Contact::getLastName(void) const
{
	return (last_name_);
}

void Contact::setLastName(std::string last_name)
{
	last_name_ = last_name;
}

std::string Contact::getNickname(void) const
{
	return (nickname_);
}

void Contact::setNickname(std::string nickname)
{
	nickname_ = nickname;
}

std::string Contact::getPhone(void) const
{
	return (phone_);
}

void Contact::setPhone(std::string phone)
{
	phone_ = phone;
}

std::string Contact::getSecret(void) const
{
	return (secret_);
}

void Contact::setSecret(std::string secret)
{
	secret_ = secret;
}

void Contact::displayDetails(void) const
{
	std::cout << "First Name: " << first_name_ << '\n';
	std::cout << "Last Name: " << last_name_ << '\n';
	std::cout << "Nickname: " << nickname_ << '\n';
	std::cout << "Phone Number: " << phone_ << '\n';
	std::cout << "Darkest Secret: " << secret_ << '\n';
}
