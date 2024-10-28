/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 08:55:20 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::m_fractionalBits(FRACTIONAL_BITS);

Fixed::Fixed(void) : m_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) : m_value(other.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	m_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (m_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	m_value = raw;
}
