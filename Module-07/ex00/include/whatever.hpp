/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/19 18:58:41 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

template <typename T> T min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T> T max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif /* WHATEVER_HPP */
