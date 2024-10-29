/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/29 16:43:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string("HI THIS IS BRAIN");
	std::string *stringPTR(&string);
	std::string &stringREF(string);
	std::cout << "Memory address of string variable: " << &string << '\n';
	std::cout << "Memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "Memory address held by stringREF: " << &stringREF << '\n';
	std::cout << "Value of string variable: " << string << '\n';
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "Value referred to by stringREF: " << stringREF << '\n';
	return (0);
}
