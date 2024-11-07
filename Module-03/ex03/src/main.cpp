/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:45:14 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("Bot");
	diamond.attack("Bender");
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.whoAmI();
	std::cout << '\n';
	FragTrap copy(diamond);
	copy.attack("Robot");
	copy.takeDamage(30);
	return (0);
}
