/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 22:18:56 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name)
{
	std::cout << "[Zombie] " << name_ << "\t → Created\n";
}

Zombie::~Zombie(void)
{
	std::cout << "[Zombie] " << name_ << "\t → Destroyed\n";
}

void Zombie::announce(void)
{
	std::cout << "[Zombie] " << name_ << "\t → BraiiiiiiinnnzzzZ...\n";
}
