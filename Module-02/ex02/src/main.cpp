/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/21 12:17:29 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed	c;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	c = Fixed(42.42f);
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, c) << std::endl;
	std::cout << Fixed(5.05f) / Fixed(2) << std::endl;
	std::cout << Fixed(2) + Fixed(2) << std::endl;
	return (0);
}
