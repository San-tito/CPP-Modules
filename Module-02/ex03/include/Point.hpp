/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/23 11:51:16 by santito          ###   ########.fr       */
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
	Point(const Point &point);
	Point &operator=(const Point &point);
	~Point(void);
	const Fixed &getX(void) const;
	const Fixed &getY(void) const;

  private:
	const Fixed x_;
	const Fixed y_;
};

#endif /* FIXED_HPP */
