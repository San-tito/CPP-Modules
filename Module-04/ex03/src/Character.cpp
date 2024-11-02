/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 21:06:20 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name_("")
{
}

Character::Character(const std::string &name) : name_(name)
{
}

Character::Character(const Character &other) : name_(other.name_)
{
	for (int i(0); i < INVENTORY_SIZE; i++)
		inventory_[i] = other.inventory_[i] ? other.inventory_[i]->clone() : 0;
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	name_ = other.name_;
	for (int i(0); i < INVENTORY_SIZE; i++)
	{
		delete (inventory_[i]);
		inventory_[i] = other.inventory_[i] ? other.inventory_[i]->clone() : 0;
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i(0); i < INVENTORY_SIZE; i++)
		delete (inventory_[i]);
}

const std::string &Character::getName(void) const
{
	return (name_);
}

void Character::equip(AMateria *m)
{
	for (int i(0); i < INVENTORY_SIZE; i++)
	{
		if (inventory_[i] == 0)
		{
			inventory_[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE)
		inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && inventory_[idx])
		inventory_[idx]->use(target);
}
