/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/07 12:42:14 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <list>
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
	std::list<int> lst_;
	size_t Jacobsthal(size_t n);
	void Display(std::vector<int> &vec);
	void Display(std::list<int> &lst);
	double TimedSort(std::vector<int> &vec);
	double TimedSort(std::list<int> &lst);
	void Sort(std::vector<int> &vec, size_t pair_size = 1);
	void Sort(std::list<int> &lst, size_t pair_size = 1);
};

#endif /* PMERGEME_HPP */
