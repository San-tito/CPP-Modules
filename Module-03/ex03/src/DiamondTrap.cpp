/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 12:24:57 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	name_ = "default";
	ClapTrap::name_ = name_ + "_clap_name";
	ClapTrap::hit_points_ = FragTrap::hit_points_;
	ClapTrap::energy_points_ = ScavTrap::energy_points_;
	ClapTrap::attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << name_ << " created!\n";
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	name_ = name;
	ClapTrap::name_ = name_ + "_clap_name";
	ClapTrap::hit_points_ = FragTrap::hit_points_;
	ClapTrap::energy_points_ = ScavTrap::energy_points_;
	ClapTrap::attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << name_ << " created!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy.name_),
	FragTrap(copy.name_), ScavTrap(copy.name_)
{
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	name_ = copy.name_;
	ClapTrap::name_ = copy.ClapTrap::name_;
	ClapTrap::hit_points_ = copy.ClapTrap::hit_points_;
	ClapTrap::energy_points_ = copy.ClapTrap::energy_points_;
	ClapTrap::attack_damage_ = copy.ClapTrap::attack_damage_;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << name_ << " destroyed!\n";
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << name_ << " and my ClapTrap name is ";
	std::cout << ClapTrap::name_ << '\n';
}
