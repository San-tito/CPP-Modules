/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 12:50:29 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	float result(0.5 * (a.getX().toFloat() * (b.getY().toFloat()
				- c.getY().toFloat()) + b.getX().toFloat() * (c.getY().toFloat()
				- a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat()
				- b.getY().toFloat())));
	return ((result < 0) ? -result : result);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float abc(area(a, b, c));
	float pbc(area(point, b, c));
	float pac(area(point, a, c));
	float pab(area(point, a, b));
	return ((abc == pbc + pac + pab) && pbc != 0 && pac != 0 && pab != 0);
}

int	main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point point(10, 15);
	bool result(bsp(a, b, c, point));
	std::cout << "The point is " << (result ? "inside" : "outside") << " the triangle\n";
	return (0);
}
