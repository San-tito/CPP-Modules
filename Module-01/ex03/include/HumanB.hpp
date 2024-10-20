/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/20 17:53:04 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon &weapon);

  private:
	std::string name_;
	Weapon *weapon_;
};

#endif /* HUMANB_HPP */
