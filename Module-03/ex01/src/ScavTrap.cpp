/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:16:44 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap " << name_ << " has been created!\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap " << name_ << " has been created!\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name_ << " has been destroyed!\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (hit_points_ <= 0)
		std::cout << "ScavTrap " << name_ << " can't attack " << target << " because it has no hit points left!\n";
	else if (energy_points_ <= 0)
		std::cout << "ScavTrap " << name_ << " can't attack " << target << " because it has no energy points left!\n";
	else
	{
		energy_points_--;
		std::cout << "ScavTrap " << name_ << " attacks " << target;
		std::cout << ", causing " << attack_damage_ << " points of damage!\n";
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name_ << " is now in Gatekeeper mode!\n";
}
