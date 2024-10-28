/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 11:49:26 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("DefaultFrag")
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap Default constructor called for " << m_name << "\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << m_name << "\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << m_name << "\n";
}

void FragTrap::attack(const std::string &target)
{
	if (m_energyPoints > 0)
	{
		std::cout << "FragTrap " << m_name << " attacks " << target;
		std::cout << ", causing " << m_attackDamage << " points of damage !\n";
		m_energyPoints--;
	}
	else
		std::cout << "FragTrap " << m_name << " has no energy left to attack!\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << m_name << " requests a high five from everyone!\n";
}
