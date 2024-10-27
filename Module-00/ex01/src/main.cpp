/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:57:51 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 19:16:49 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;

	std::string command;
	do
	{
		std::cerr << "┌─[phoneBook]\n└─$ ";
		std::getline(std::cin, command);
		if (command == "ADD")
			book.add();
		else if (command == "SEARCH")
			book.search();
		else if (command == "EXIT")
			return (std::cin.fail());
	} while (std::cin.good());
	std::cerr << '\n';
	return (std::cin.fail());
}
