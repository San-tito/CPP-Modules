/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 12:19:40 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type_("")
{
	std::cout << "AAnimal constructed\n";
}

AAnimal::AAnimal(const AAnimal &other) : type_(other.type_)
{
	std::cout << "AAnimal copy-constructed\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructed\n";
}

std::string AAnimal::getType() const
{
	return (type_);
}
