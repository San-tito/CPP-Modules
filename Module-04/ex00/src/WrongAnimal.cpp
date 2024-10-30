/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:37:47 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type_("")
{
	std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_)
{
	std::cout << "WrongAnimal copy-constructed\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type_ = other.type_;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!\n";
}

std::string WrongAnimal::getType() const
{
	return (type_);
}
