/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/20 19:11:32 by santito          ###   ########.fr       */
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
				if (s1.empty())
					break ;
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
	return (replace(argv[1], argv[2], argv[3]));
}
