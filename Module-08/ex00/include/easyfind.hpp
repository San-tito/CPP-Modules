/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/21 09:39:29 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <vector>

template <typename T> typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			break ;
	}
	return (it);
}

#endif /* EASYFIND_HPP */
