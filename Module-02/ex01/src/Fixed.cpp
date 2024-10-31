/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/31 14:43:13 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits_(FRACTIONAL_BITS);

Fixed::Fixed(void) : value_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) : value_(other.value_)
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) : value_(value << fractional_bits_)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : value_(roundf(value
		* (1 << fractional_bits_)))
{
	std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	value_ = other.value_;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	value_ = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value_) / (1 << fractional_bits_));
}

int Fixed::toInt(void) const
{
	return (value_ >> fractional_bits_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
