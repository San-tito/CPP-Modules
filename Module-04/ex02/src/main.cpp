/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 12:32:48 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// const AAnimal *animal(new AAnimal());
	const AAnimal *dog(new Dog());
	const AAnimal *cat(new Cat());
	std::cout << dog->getType() << " \n";
	std::cout << cat->getType() << " \n";
	cat->makeSound();
	dog->makeSound();
	delete (dog);
	delete (cat);
	return (0);
}
