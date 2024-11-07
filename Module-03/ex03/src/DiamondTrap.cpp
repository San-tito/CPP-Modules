/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 13:02:10 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DiamondTrap_clap_name"),
	ScavTrap("DiamondTrap"), FragTrap("DiamondTrap"), name_("DiamondTrap")
{
	hit_points_ = FragTrap::hit_points_;
	energy_points_ = ScavTrap::energy_points_;
	attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << name_ << " has been created!\n";
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name
	+ "_clap_name"), ScavTrap(name), FragTrap(name), name_(name)
{
	hit_points_ = FragTrap::hit_points_;
	energy_points_ = ScavTrap::energy_points_;
	attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << name_ << " has been created!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other), name_(other.name_)
{
	std::cout << "DiamondTrap " << name_ << " has been created!\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	name_ = other.name_;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << name_ << " has been destroyed!\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << name_ << " and my ClapTrap name is " << ClapTrap::name_ << "\n";
}
