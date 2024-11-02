/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 12:17:59 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type_("")
{
	std::cout << "Animal constructed\n";
}

Animal::Animal(const Animal &other) : type_(other.type_)
{
	std::cout << "Animal copy-constructed\n";
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructed\n";
}

void Animal::makeSound() const
{
	std::cout << "Animal sound!\n";
}

std::string Animal::getType() const
{
	return (type_);
}
