/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/20 17:18:40 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string("HI THIS IS BRAIN");
	std::string *stringPTR(&string);
	std::string &stringREF(string);
	std::cout << "memory address of string: " << &string << '\n';
	std::cout << "memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "memory address held by stringREF: " << &stringREF << '\n';
	std::cout << "value of the string: " << string << '\n';
	std::cout << "value pointed by stringPTR: " << *stringPTR << '\n';
	std::cout << "value pointed by stringRED: " << stringREF << '\n';
	return (0);
}
