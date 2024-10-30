/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:02:38 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("DefaultScav")
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap Default constructor called for " << name_ << "\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap constructor called for " << name_ << "\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << name_ << "\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points_ > 0)
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target;
		std::cout << ", causing " << attack_damage_ << " points of damage !\n";
		energy_points_--;
	}
	else
		std::cout << "ScavTrap " << name_ << " has no energy left to attack!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " is now in Gatekeeper mode!\n";
}
