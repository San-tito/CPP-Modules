/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/31 14:41:09 by sguzman          ###   ########.fr       */
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
	std::cout << "getRawBits member function called\n";
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	value_ = raw;
}
