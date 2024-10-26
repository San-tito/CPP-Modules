/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 13:18:38 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy)
{
	m_type = copy.m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof\n";
}
