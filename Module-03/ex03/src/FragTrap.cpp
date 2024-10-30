/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:02:25 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("DefaultFrag")
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap Default constructor called for " << name_ << "\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap constructor called for " << name_ << "\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << name_ << "\n";
}

void FragTrap::attack(const std::string &target)
{
	if (energy_points_ > 0)
	{
		std::cout << "FragTrap " << name_ << " attacks " << target;
		std::cout << ", causing " << attack_damage_ << " points of damage !\n";
		energy_points_--;
	}
	else
		std::cout << "FragTrap " << name_ << " has no energy left to attack!\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_ << " requests a high five from everyone!\n";
}
