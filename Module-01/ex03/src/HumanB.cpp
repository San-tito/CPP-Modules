/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 10:51:02 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (weapon_)
		std::cout << name_ << " attacks with their " << weapon_->getType() << '\n';
	else
		std::cout << name_ << " has no weapon to attack with.\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
