/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/25 11:57:10 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	std::ifstream file(argv[1]);
	if (file.is_open() == 0)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	std::ifstream db("data.csv");
	if (db.is_open() == 0)
	{
		std::cerr << "Error: could not open db file.\n";
		file.close();
		return (1);
	}
	BitcoinExchange bitcoinExchange(db);
	std::string line;
	while (std::getline(file, line))
	{
		try
		{
			std::string result = bitcoinExchange.computeLine(line);
			std::cout << result << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	file.close();
	db.close();
	return (0);
}
