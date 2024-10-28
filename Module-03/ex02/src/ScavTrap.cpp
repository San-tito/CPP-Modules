/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 11:55:42 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("DefaultScav")
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called for " << m_name << "\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << m_name << "\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << m_name << "\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (m_energyPoints > 0)
	{
		std::cout << "ScavTrap " << m_name << " attacks " << target;
		std::cout << ", causing " << m_attackDamage << " points of damage !\n";
		m_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << m_name << " has no energy left to attack!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << m_name << " is now in Gatekeeper mode!\n";
}
