/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 10:46:00 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name_("default")
{
	std::cout << name_ << ": Created\n";
}

Zombie::Zombie(std::string name) : name_(name)
{
	std::cout << name_ << ": Created\n";
}

Zombie::~Zombie(void)
{
	std::cout << name_ << ": Destroyed\n";
}

void Zombie::announce(void) const
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
