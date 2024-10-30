/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/30 11:43:14 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const Animal *animal(new Animal());
		const Animal *dog(new Dog());
		const Animal *cat(new Cat());
		std::cout << dog->getType() << " \n";
		std::cout << cat->getType() << " \n";
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		delete (animal);
		delete (dog);
		delete (cat);
	}
	{
		const WrongAnimal *animal(new WrongAnimal());
		const WrongAnimal *cat(new WrongCat());
		std::cout << cat->getType() << " \n";
		cat->makeSound();
		animal->makeSound();
		delete (animal);
		delete (cat);
	}
	return (0);
}
