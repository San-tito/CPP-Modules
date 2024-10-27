/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 21:00:28 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>

int	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename.data());
	if (file.fail())
	{
		std::cerr << filename << ": " << strerror(errno) << '\n';
		return (1);
	}
	std::ofstream output((filename + ".replace").data());
	if (output.fail())
	{
		file.close();
		std::cerr << (filename + ".replace") << ": " << strerror(errno) << '\n';
		return (1);
	}
	{
		std::size_t found;
		std::string line;
		while (std::getline(file, line))
		{
			while ((found = line.find(s1)) != std::string::npos)
			{
				line.erase(found, s1.length());
				line.insert(found, s2);
			}
			output << line << '\n';
		}
	}
	file.close();
	output.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << *argv << " <filename> <s1> <s2>\n";
		return (1);
	}
	std::string s1(argv[2]);
	if (s1.empty())
	{
		std::cerr << "Error: The string to be replaced (s1) cannot be empty.\n";
		return (1);
	}
	return (replace(argv[1], s1, argv[3]));
}
