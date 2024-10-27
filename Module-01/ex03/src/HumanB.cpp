/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 20:54:23 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_pweapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (m_pweapon)
		std::cout << m_name << " attacks with their " << m_pweapon->getType() << '\n';
	else
		std::cout << m_name << " has no weapon to attack with.\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	m_pweapon = &weapon;
}
