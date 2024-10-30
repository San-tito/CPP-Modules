/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 10:10:42 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DefaultDiamond_clap_name"),
	FragTrap("DefaultDiamond"), ScavTrap("DefaultDiamond"),
	m_name("DefaultDiamond")
{
	m_hitPoints = FragTrap::m_hitPoints;
	m_energyPoints = ScavTrap::m_energyPoints;
	m_attackDamage = FragTrap::m_attackDamage;
	std::cout << "DiamondTrap Default constructor called for " << m_name << "\n";
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name
	+ "_clap_name"), FragTrap(name), ScavTrap(name), m_name(name)
{
	m_hitPoints = FragTrap::m_hitPoints;
	m_energyPoints = ScavTrap::m_energyPoints;
	m_attackDamage = FragTrap::m_attackDamage;
	std::cout << "DiamondTrap constructor called for " << m_name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScavTrap(other), m_name(other.m_name)
{
	std::cout << "DiamondTrap copy constructor called for " << m_name << "\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
	m_name = other.m_name;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << m_name << "\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << m_name << " and my ClapTrap name is " << ClapTrap::m_name << "\n";
}
