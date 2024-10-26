/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/26 19:45:14 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "Creating an Animal instance\n";
		const Animal *animal(new Animal());
		std::cout << "Animal type: " << animal->getType() << "\n";
		(*animal).makeSound();
		delete (animal);
	}
	{
		std::cout << "\nCreating a Dog instance:\n";
		const Animal *dog(new Dog());
		std::cout << "Animal type: " << dog->getType() << "\n";
		dog->makeSound();
		delete (dog);
	}
	{
		std::cout << "\nCreating a Cat instance:\n";
		const Animal *cat(new Cat());
		std::cout << "Animal type: " << cat->getType() << "\n";
		cat->makeSound();
		delete (cat);
	}
	{
		std::cout << "\nUsing polymorphism with Animal pointers:\n";
		const Animal *polyDog(new Dog());
		const Animal *polyCat(new Cat());
		std::cout << "polyDog type: " << polyDog->getType() << "\n";
		std::cout << "polyCat type: " << polyCat->getType() << "\n";
		polyDog->makeSound();
		polyCat->makeSound();
		delete (polyDog);
		delete (polyCat);
	}
	{
		std::cout << "\nCreating instances of WrongAnimal and WrongCat:\n";
		const WrongAnimal *wrongAnimal(new WrongAnimal());
		const WrongAnimal *wrongCat(new WrongCat());
		std::cout << "wrongAnimal type: " << wrongAnimal->getType() << "\n";
		std::cout << "wrongCat type: " << wrongCat->getType() << "\n";
		wrongAnimal->makeSound();
		wrongCat->makeSound();
		delete (wrongAnimal);
		delete (wrongCat);
	}
	{
		std::cout << "\nCreating a direct WrongCat instance:\n";
		const WrongCat *directWrongCat(new WrongCat());
		std::cout << "directWrongCat type: " << directWrongCat->getType() << "\n";
		directWrongCat->makeSound();
		delete (directWrongCat);
	}
	return (0);
}
