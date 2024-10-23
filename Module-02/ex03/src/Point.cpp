/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/23 16:54:15 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) : x_(x), y_(y)
{
}

Point::Point(const Point &point)
{
	*this = point;
}

Point &Point::operator=(const Point &point)
{
	if (this == &point)
		return (*this);
	const_cast<Fixed &>(x_) = point.getX();
	const_cast<Fixed &>(y_) = point.getY();
	return (*this);
}

Point::~Point(void)
{
}

Fixed &Point::getX(void) const
{
	return (const_cast<Fixed &>(x_));
}

Fixed &Point::getY(void) const
{
	return (const_cast<Fixed &>(y_));
}
