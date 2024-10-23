/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/23 11:54:01 by santito          ###   ########.fr       */
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
	return (*this);
}

Point::~Point(void)
{
}

const Fixed &Point::getX(void) const
{
	return (x_);
}

const Fixed &Point::getY(void) const
{
	return (y_);
}
