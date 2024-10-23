/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/23 11:02:45 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits_(WIDTH);

Fixed::Fixed(void) : value_(0)
{
}

Fixed::Fixed(const int value)
{
	value_ = value * (1 << bits_);
}

Fixed::Fixed(const float value)
{
	value_ = roundf(value * (1 << bits_));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	value_ = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (value_ > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (value_ < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (value_ >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (value_ <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (value_ == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (value_ != fixed.getRawBits());
}

Fixed &Fixed::operator+(const Fixed &fixed)
{
	value_ += fixed.getRawBits();
	return (*this);
}

Fixed &Fixed::operator-(const Fixed &fixed)
{
	value_ -= fixed.getRawBits();
	return (*this);
}

Fixed &Fixed::operator*(const Fixed &fixed)
{
	value_ *= fixed.getRawBits();
	value_ >>= bits_;
	return (*this);
}

Fixed &Fixed::operator/(const Fixed &fixed)
{
	value_ /= fixed.getRawBits();
	value_ >>= bits_;
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	value_++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	value_--;
	return (*this);
}

Fixed &Fixed::operator++(int)
{
	++(*this);
	return (*this);
}

Fixed &Fixed::operator--(int)
{
	--(*this);
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (min(const_cast<Fixed &>(f1), const_cast<Fixed &>(f2)));
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (max(const_cast<Fixed &>(f1), const_cast<Fixed &>(f2)));
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
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	value_ = raw;
}
