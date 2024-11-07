/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 11:51:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name_("ClapTrap"), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << name_ << " has been created!\n";
}

ClapTrap::ClapTrap(const std::string &name) : name_(name), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << name_ << " has been created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name_(other.name_),
	hit_points_(other.hit_points_), energy_points_(other.energy_points_),
	attack_damage_(other.attack_damage_)
{
	std::cout << "ClapTrap " << name_ << " has been created!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name_ << " has been destroyed!\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (hit_points_ <= 0)
		std::cout << "ClapTrap " << name_ << " can't attack " << target << " because it has no hit points left!\n";
	else if (energy_points_ <= 0)
		std::cout << "ClapTrap " << name_ << " can't attack " << target << " because it has no energy points left!\n";
	else
	{
		energy_points_--;
		std::cout << "ClapTrap " << name_ << " attacks " << target;
		std::cout << ", causing " << attack_damage_ << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points_ == 0)
		std::cout << "ClapTrap " << name_ << " can't take more damage because it has no hit points left!\n";
	else
	{
		hit_points_ = (amount >= hit_points_) ? 0 : hit_points_ - amount;
		std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage! Remaining hit points: " << hit_points_ << '\n';
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points_ <= 0)
		std::cout << "ClapTrap " << name_ << " can't repair itself because it has no hit points left!\n";
	else if (energy_points_ <= 0)
		std::cout << "ClapTrap " << name_ << " can't repair itself because it has no energy points left!\n";
	else
	{
		hit_points_ += amount;
		energy_points_--;
		std::cout << "ClapTrap " << name_ << " repairs itself, restoring ";
		std::cout << amount << " hit points! Current hit points: " << hit_points_ << '\n';
	}
}
