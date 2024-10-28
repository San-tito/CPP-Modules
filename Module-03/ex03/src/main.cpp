/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 12:21:51 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap techWarrior("TechnoKnight");
	ScavTrap repairBot("RepairRover");
	FragTrap fragHero("FragMaster");
	DiamondTrap diamondBeast("DiamondWarrior");
	techWarrior.attack("GiantSlime");
	techWarrior.takeDamage(5);
	techWarrior.beRepaired(3);
	repairBot.attack("MightyDragon");
	repairBot.takeDamage(10);
	repairBot.beRepaired(5);
	repairBot.guardGate();
	fragHero.attack("ShadowBeast");
	fragHero.takeDamage(15);
	fragHero.beRepaired(10);
	fragHero.highFivesGuys();
	diamondBeast.attack("InfernalWyrm");
	diamondBeast.takeDamage(20);
	diamondBeast.beRepaired(15);
	diamondBeast.whoAmI();
	return (0);
}
