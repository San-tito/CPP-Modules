/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 13:24:42 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
  public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	~Animal(void);
	virtual void makeSound(void) const;

  protected:
	std::string m_type;
};

#endif /* ANIMAL_HPP */
