/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/21 11:24:46 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits_(WIDTH);

Fixed::Fixed(void) : value_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	value_ = value << bits_;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	value_ = roundf(value * (1 << bits_));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	value_ = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value_) / (1 << bits_));
}

int Fixed::toInt(void) const
{
	return (value_ >> bits_);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	value_ = raw;
}
