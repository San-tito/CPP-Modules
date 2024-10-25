/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 19:51:15 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap " << name_ << " created!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap " << name_ << " created!\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name_)
{
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	name_ = copy.name_;
	hit_points_ = copy.hit_points_;
	energy_points_ = copy.energy_points_;
	attack_damage_ = copy.attack_damage_;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name_ << " destroyed!\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points_ > 0)
	{
		std::cout << "ScavTrap " << name_ << " attacks ";
		std::cout << target << ", causing " << attack_damage_;
		std::cout << " points of damage !\n";
		energy_points_--;
	}
	else
		std::cout << "ClapTrap " << name_ << " out of Energy!\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name_ << " have enterred in Gate keeper mode\n";
}
