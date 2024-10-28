/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 09:34:59 by santito          ###   ########.fr       */
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

Fixed::Fixed(const int value) : m_value(value << m_fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : m_value(roundf(value
		* (1 << m_fractionalBits)))
{
	std::cout << "Float constructor called\n";
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
	return (m_value);
}

void Fixed::setRawBits(int const raw)
{
	m_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(m_value) / (1 << m_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (m_value >> m_fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
