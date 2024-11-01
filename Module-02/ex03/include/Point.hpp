/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/01 17:14:07 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;

  private:
	const Fixed x_;
	const Fixed y_;
};

#endif /* FIXED_HPP */
