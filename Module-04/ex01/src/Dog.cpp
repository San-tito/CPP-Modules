/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 12:19:29 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << "Dog constructed\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain_ = new Brain(*other.brain_);
	std::cout << "Dog copy-constructed\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete (brain_);
	brain_ = new Brain(*other.brain_);
	return (*this);
}

Dog::~Dog(void)
{
	delete (brain_);
	std::cout << "Dog destructed\n";
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}
