/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 12:12:09 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructed\n";
}

Brain::Brain(const Brain &other)
{
	for (int i(0); i < IDEAS_SIZE; i++)
		ideas_[i] = other.ideas_[i];
	std::cout << "Brain copy-constructed\n";
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i(0); i < IDEAS_SIZE; i++)
		ideas_[i] = other.ideas_[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed\n";
}