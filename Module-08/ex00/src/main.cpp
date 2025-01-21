/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/21 09:44:52 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::vector<int>::iterator it(easyfind(vec, 5));
	if (it != vec.end())
		std::cout << "Found: " << *it << "\n";
	else
		std::cout << "Not found\n";
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	std::list<int>::iterator lst_it(easyfind(lst, 30));
	if (lst_it != lst.end())
		std::cout << "Found: " << *lst_it << "\n";
	else
		std::cout << "Not found\n";
	std::vector<int>::iterator not_found(easyfind(vec, 10));
	if (not_found != vec.end())
		std::cout << "Found: " << *not_found << "\n";
	else
		std::cout << "Not found\n";
	return (0);
}
