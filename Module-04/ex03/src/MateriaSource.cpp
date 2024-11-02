/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 21:01:43 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i(0); i < SOURCE_SIZE; i++)
		materias_[i] = other.materias_[i] ? other.materias_[i]->clone() : 0;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return (*this);
	for (int i(0); i < SOURCE_SIZE; i++)
	{
		delete (materias_[i]);
		materias_[i] = other.materias_[i] ? other.materias_[i]->clone() : 0;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i(0); i < SOURCE_SIZE; i++)
		delete (materias_[i]);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i(0); i < SOURCE_SIZE; i++)
	{
		if (materias_[i] == 0)
		{
			materias_[i] = m;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i(0); i < SOURCE_SIZE; i++)
	{
		if (materias_[i] && materias_[i]->getType() == type)
			return (materias_[i]->clone());
	}
	return (0);
}
