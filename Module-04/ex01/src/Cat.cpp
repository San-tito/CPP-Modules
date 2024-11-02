/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 12:19:06 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "Cat constructed\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	brain_ = new Brain(*other.brain_);
	std::cout << "Cat copy-constructed\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete (brain_);
	brain_ = new Brain(*other.brain_);
	return (*this);
}

Cat::~Cat(void)
{
	delete (brain_);
	std::cout << "Cat destructed\n";
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
