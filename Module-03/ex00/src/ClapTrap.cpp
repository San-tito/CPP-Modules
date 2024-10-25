/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 17:18:54 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name_("default"), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << name_ << " created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_points_(10),
	energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap " << name_ << " created!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	name_ = copy.name_;
	hit_points_ = copy.hit_points_;
	energy_points_ = copy.energy_points_;
	attack_damage_ = copy.attack_damage_;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name_ << " destroyed!\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_points_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " attacks ";
		std::cout << target << ", causing " << attack_damage_;
		std::cout << " points of damage !\n";
		energy_points_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " out of Energy!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points_ == 0)
		std::cout << "ClapTrap " << name_ << " already dead!\n";
	else
	{
		std::cout << "ClapTrap " << name_ << " takes ";
		std::cout << amount << " points of damage!\n";
		while (amount-- && hit_points_)
			hit_points_--;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " repairs ";
		std::cout << amount << " points of health!\n";
		hit_points_ += amount;
		energy_points_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " out of Energy!\n";
}
