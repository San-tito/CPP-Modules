/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:15:52 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap guardian("Guardian");
	guardian.attack("Zap Brannigan");
	guardian.takeDamage(30);
	guardian.beRepaired(10);
	guardian.guardGate();
	std::cout << '\n';
	ScavTrap protector(guardian);
	protector.attack("Bender");
	protector.takeDamage(50);
	protector.guardGate();
	return (0);
}
