/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:28:16 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap frag("Boomer");
	frag.attack("Scavenger");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();
	std::cout << '\n';
	FragTrap frag_copy(frag);
	frag_copy.attack("Bender");
	frag_copy.takeDamage(30);
	return (0);
}
