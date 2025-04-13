/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/13 20:43:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <ctime>
# include <deque>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <vector>

class PmergeMe
{
  public:
	PmergeMe(int argc, char *argv[]);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	void Run(void);

  private:
	std::vector<int> vec_;
	std::deque<int> deq_;
	size_t Jacobsthal(size_t n);
	template <typename T> void Display(T &container);
	template <typename T> double TimedSort(T &container);
	template <typename T> void Sort(T &container, size_t elem_size = 1);
	template <typename T> T BinarySearch(T low, T high, size_t e, int value);
};

#endif /* PMERGEME_HPP */
