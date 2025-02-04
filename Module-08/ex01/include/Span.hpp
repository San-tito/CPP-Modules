/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/04 13:18:34 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <vector>

class Span
{
  public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	void addNumber(int N);
	template <class It> void addNumber(It begin, It end);
	int shortestSpan(void) const;
	int longestSpan(void) const;

  private:
	unsigned int size_;
	std::vector<int> numbers_;
};

#endif /* SPAN_HPP */
