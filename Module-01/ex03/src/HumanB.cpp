/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/29 16:49:15 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_pWeapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	if (m_pWeapon)
		std::cout << m_name << " attacks with their " << m_pWeapon->getType() << '\n';
	else
		std::cout << m_name << " has no weapon to attack with.\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	m_pWeapon = &weapon;
}
