/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 19:45:24 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type)
{
	std::cout << "WrongAnimal argument constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : m_type(copy.m_type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	m_type = copy.m_type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType() const
{
	return (m_type);
}

void WrongAnimal::makeSound() const
{
}
