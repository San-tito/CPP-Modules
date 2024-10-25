/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 19:57:56 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap " << name_ << " created!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap " << name_ << " created!\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.name_)
{
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	name_ = copy.name_;
	hit_points_ = copy.hit_points_;
	energy_points_ = copy.energy_points_;
	attack_damage_ = copy.attack_damage_;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name_ << " destroyed!\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name_ << " requests a high five!\n";
}
