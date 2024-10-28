/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 11:50:59 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap techWarrior("TechnoKnight");
	ScavTrap repairBot("RepairRover");
	FragTrap fragHero("FragMaster");
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
	FragTrap cloneHero(fragHero);
	cloneHero.attack("InfernalWyrm");
	cloneHero.highFivesGuys();
	techWarrior = fragHero;
	techWarrior.attack("DragonKing");
	return (0);
}
