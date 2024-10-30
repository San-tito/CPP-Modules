/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:00:02 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name_("Default"), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap Default constructor called for " << name_ << "\n";
}

ClapTrap::ClapTrap(const std::string &name) : name_(name), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap constructor called for " << name_ << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name_(other.name_),
	hit_points_(other.hit_points_), energy_points_(other.energy_points_),
	attack_damage_(other.attack_damage_)
{
	std::cout << "ClapTrap copy constructor called for " << name_ << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << name_ << "\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_points_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target;
		std::cout << ", causing " << attack_damage_ << " points of damage !\n";
		energy_points_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " has no energy left to attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= hit_points_)
	{
		hit_points_ = 0;
		std::cout << "ClapTrap " << name_ << " has taken too much damage and is destroyed!\n";
	}
	else
	{
		hit_points_ -= amount;
		std::cout << "ClapTrap " << name_ << " now has " << hit_points_ << " hit points left.\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points_ > 0)
	{
		hit_points_ += amount;
		energy_points_--;
		std::cout << "ClapTrap " << name_ << " repairs itself, restoring ";
		std::cout << amount << " hit points. Total hit points: " << hit_points_ << "\n";
	}
	else
		std::cout << "ClapTrap " << name_ << " has no energy left to repair!\n";
}
