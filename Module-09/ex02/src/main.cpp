/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/09 21:38:23 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container> void printContainer(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << '\n';
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: invalid number of arguments.\n";
		return (1);
	}
	try
	{
		std::vector<int> vec;
		std::deque<int> deq;
		for (int i = 1; i < argc; i++)
		{
			int num(0);
			std::istringstream iss(argv[i]);
			if (!(iss >> num) || num < 0)
				throw std::invalid_argument("Error: invalid argument: "
					+ std::string(argv[i]));
			vec.push_back(num);
			deq.push_back(num);
		}
		::PmergeMe pmergeMe;
		std::cout << "Before (std::vector): ";
		printContainer(vec);
		double time_vector(pmergeMe.timedSort(vec));
		std::cout << "After (std::vector): ";
		printContainer(vec);
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << time_vector << " seconds.\n";
		std::cout << "Before (std::deque): ";
		printContainer(deq);
		double time_deque(pmergeMe.timedSort(deq));
		std::cout << "After (std::deque): ";
		printContainer(deq);
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << time_deque << " seconds.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
