/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:38:33 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type_ = "WrongCat";
	std::cout << "WrongCat constructed\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow!\n";
}
