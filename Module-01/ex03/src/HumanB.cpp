/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/20 17:53:35 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
	std::cout << name_ << " attacks with their " << (*weapon_).getType() << '\n';
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
