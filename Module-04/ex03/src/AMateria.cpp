/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/02 12:51:42 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type_("")
{
}

AMateria::AMateria(const std::string &type) : type_(type)
{
}

AMateria::AMateria(const AMateria &other) : type_(other.type_)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return (*this);
	type_ = other.type_;
	return (*this);
}

AMateria::~AMateria(void)
{
}

const std::string &AMateria::getType() const
{
	return (type_);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Using materia on " << target.getName() << "\n";
}
