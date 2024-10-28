/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 11:22:36 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap techWarrior("TechnoKnight");
	ClapTrap repairBot("RepairRover");
	techWarrior.attack("GiantSlime");
	techWarrior.takeDamage(5);
	techWarrior.beRepaired(3);
	repairBot.attack("MightyDragon");
	repairBot.takeDamage(10);
	repairBot.beRepaired(5);
	ClapTrap cloneBot(repairBot);
	cloneBot.attack("ShadowBeast");
	techWarrior = repairBot;
	techWarrior.attack("InfernalWyrm");
	return (0);
}
