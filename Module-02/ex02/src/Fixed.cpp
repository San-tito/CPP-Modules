/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 09:56:10 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::m_fractionalBits = FRACTIONAL_BITS;

Fixed::Fixed(void) : m_value(0)
{
}

Fixed::Fixed(const Fixed &other) : m_value(other.getRawBits())
{
}

Fixed::Fixed(const int value)
{
	m_value = value << m_fractionalBits;
}

Fixed::Fixed(const float value)
{
	m_value = roundf(value * (1 << m_fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	m_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
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

bool Fixed::operator>(const Fixed &other) const
{
	return (m_value > other.m_value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (m_value < other.m_value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (m_value >= other.m_value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (m_value <= other.m_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (m_value == other.m_value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (m_value != other.m_value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(m_value + other.m_value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(m_value - other.m_value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((m_value * other.m_value) >> m_fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((m_value << m_fractionalBits) / other.m_value);
	return (result);
}

Fixed &Fixed::operator++()
{
	m_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed &Fixed::operator--()
{
	m_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
