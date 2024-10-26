/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 13:27:29 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(std::string type) : m_type(type)
{
	std::cout << "Animal argument constructor called\n";
}

Animal::Animal(const Animal &copy) : m_type(copy.m_type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &copy)
{
	m_type = copy.m_type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}
