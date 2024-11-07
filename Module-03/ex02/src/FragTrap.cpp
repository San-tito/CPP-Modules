/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:25:09 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap " << name_ << " has been created!\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap " << name_ << " has been created!\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name_ << " has been destroyed!\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_ << " requests a high five from everyone!\n";
}
