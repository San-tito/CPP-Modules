/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/25 16:53:46 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void) const;
	int getHealth(void) const;
	int getEnergy(void) const;
	int getAttack(void) const;

  private:
	std::string name_;
	int health_;
	int energy_;
	int attack_;
};

#endif /* CLAPTRAP_HPP */
