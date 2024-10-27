/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 20:08:44 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : m_name(name)
{
	std::cout << m_name << ": Created\n";
}

Zombie::~Zombie(void)
{
	std::cout << m_name << ": Destroyed\n";
}

void Zombie::announce(void) const
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}
