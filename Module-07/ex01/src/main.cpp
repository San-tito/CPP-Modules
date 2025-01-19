/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/19 20:33:52 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print(int &x)
{
	std::cout << x << " ";
}

void	print(std::string &s)
{
	std::cout << s << " ";
}

void	inc(int &x)
{
	x++;
}

int	main(void)
{
	int	tab[5] = {0, 1, 2, 3, 4};

	std::cout << "int array: ";
	iter(tab, 5, print);
	std::cout << "\n";
	iter(tab, 5, inc);
	std::cout << "int array after increment: ";
	iter(tab, 5, print);
	std::cout << "\n";
	std::string arr[5] = {"C++", "is", "a", "crazy", "language"};
	std::cout << "string array: ";
	iter(arr, 5, print);
	std::cout << "\n";
	return (0);
}
