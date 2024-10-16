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

Contact::Contact() : first_name_(""), last_name_(""), nickname_(""), phone_(""),
	secret_("")
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const
{
	return (first_name_);
}

void Contact::setFirstName(std::string first_name)
{
	first_name_ = first_name;
}

std::string Contact::getLastName() const
{
	return (last_name_);
}

void Contact::setLastName(std::string last_name)
{
	last_name_ = last_name;
}

std::string Contact::getNickname() const
{
	return (nickname_);
}

void Contact::setNickname(std::string nickname)
{
	nickname_ = nickname;
}
