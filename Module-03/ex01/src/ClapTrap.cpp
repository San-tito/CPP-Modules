/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 11:53:56 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_name("Default"), m_hitPoints(10),
	m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called for " << m_name << "\n";
}

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_hitPoints(10),
	m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << m_name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : m_name(other.m_name),
	m_hitPoints(other.m_hitPoints), m_energyPoints(other.m_energyPoints),
	m_attackDamage(other.m_attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << m_name << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << m_name << "\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (m_energyPoints > 0)
	{
		std::cout << "ClapTrap " << m_name << " attacks " << target;
		std::cout << ", causing " << m_attackDamage << " points of damage !\n";
		m_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << m_name << " has no energy left to attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= m_hitPoints)
	{
		m_hitPoints = 0;
		std::cout << "ClapTrap " << m_name << " has taken too much damage and is destroyed!\n";
	}
	else
	{
		m_hitPoints -= amount;
		std::cout << "ClapTrap " << m_name << " now has " << m_hitPoints << " hit points left.\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints > 0)
	{
		m_hitPoints += amount;
		m_energyPoints--;
		std::cout << "ClapTrap " << m_name << " repairs itself, restoring ";
		std::cout << amount << " hit points. Total hit points: " << m_hitPoints << "\n";
	}
	else
		std::cout << "ClapTrap " << m_name << " has no energy left to repair!\n";
}
