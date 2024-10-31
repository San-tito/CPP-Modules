/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/31 14:45:24 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits_ = FRACTIONAL_BITS;

Fixed::Fixed(void) : value_(0)
{
}

Fixed::Fixed(const Fixed &other) : value_(other.value_)
{
}

Fixed::Fixed(const int value)
{
	value_ = value << fractional_bits_;
}

Fixed::Fixed(const float value)
{
	value_ = roundf(value * (1 << fractional_bits_));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	value_ = other.value_;
	return (*this);
}

Fixed::~Fixed(void)
{
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

bool Fixed::operator>(const Fixed &other) const
{
	return (value_ > other.value_);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (value_ < other.value_);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (value_ >= other.value_);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (value_ <= other.value_);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (value_ == other.value_);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (value_ != other.value_);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(value_ + other.value_);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(value_ - other.value_);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((value_ * other.value_) >> fractional_bits_);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((value_ << fractional_bits_) / other.value_);
	return (result);
}

Fixed &Fixed::operator++()
{
	value_ += 1;
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
	value_ -= 1;
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
