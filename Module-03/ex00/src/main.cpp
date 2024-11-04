/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/04 23:05:27 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap hero("Hero");
	ClapTrap villain("Villain");
	hero.attack("Villain");
	villain.takeDamage(0);
	villain.attack("Hero");
	hero.takeDamage(0);
	hero.beRepaired(5);
	hero.attack("Villain");
	villain.takeDamage(0);
	return (0);
}
