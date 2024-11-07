/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/07 12:09:21 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bender("Bender");
	bender.attack("Zap Brannigan");
	bender.takeDamage(4);
	bender.beRepaired(2);
	std::cout << '\n';
	ClapTrap zoidberg("Dr. Zoidberg");
	zoidberg.attack("Leela");
	zoidberg.takeDamage(6);
	zoidberg.beRepaired(3);
	std::cout << '\n';
	ClapTrap fry(zoidberg);
	fry.attack("Bender");
	fry.takeDamage(5);
	std::cout << '\n';
	ClapTrap leela(bender);
	leela.attack("Zoidberg");
	return (0);
}
