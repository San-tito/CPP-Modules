/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 16:54:39 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name_("ClapTrap"), health_(10), energy_(10),
	attack_(0)
{
	std::cout << "ClapTrap " << name_ << " created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::ClapTrap(std::string name) : name_(name), health_(10), energy_(10),
	attack_(0)
{
	std::cout << "ClapTrap " << name_ << " created!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	name_ = copy.getName();
	health_ = copy.getHealth();
	energy_ = copy.getEnergy();
	attack_ = copy.getAttack();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name_ << " destroyed!\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " attacks ";
		std::cout << target << ", causing " << attack_;
		std::cout << " points of damage !\n";
		energy_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " out of Energy!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name_ << " takes ";
	std::cout << amount << " points of damage!\n";
	health_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " repairs ";
		std::cout << amount << " points of health!\n";
		health_ += amount;
		energy_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " out of Energy!\n";
}

std::string ClapTrap::getName(void) const
{
	return (name_);
}

int ClapTrap::getHealth(void) const
{
	return (health_);
}

int ClapTrap::getEnergy(void) const
{
	return (energy_);
}

int ClapTrap::getAttack(void) const
{
	return (attack_);
}
