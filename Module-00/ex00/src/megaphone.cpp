/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:16:09 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 18:48:31 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	loud(void)
{
	std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

void	touppercase(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(toupper(argv[i][j]));
}

int	main(int argc, char **argv)
{
	(argc < 2) ? (loud()) : (touppercase(argc, argv));
	std::cout << '\n';
	return (0);
}
