/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/17 14:50:33 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.id = 42;
	data.name = "sguzman";
	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);
	if (ptr == &data)
	{
		std::cout << "Data ID: " << ptr->id << "\n";
		std::cout << "Data Name: " << ptr->name << "\n";
	}
	return (0);
}
