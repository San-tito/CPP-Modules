/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 10:11:57 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0)
{
}

Point::Point(const float x, const float y) : m_x(x), m_y(y)
{
}

Point::Point(const Point &other) : m_x(other.m_x), m_y(other.m_y)
{
}

Point &Point::operator=(const Point &other)
{
	static_cast<void>(other);
	return (*this);
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return (m_x);
}

Fixed Point::getY(void) const
{
	return (m_y);
}
