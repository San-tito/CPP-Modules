/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/23 11:31:32 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate the area
}

int	main(void)
{
	Point a(0, 0);
	Point b(a);
	Point c(1, 1);
	Point point(0, 0);
	bool result(bsp(a, b, c, point));
	std::cout << "The point is " << (result ? "inside" : "outside") << " the triangel\n";
	return (0);
}
