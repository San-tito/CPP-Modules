/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/10 11:49:49 by sguzman          ###   ########.fr       */
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
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	template <typename Container> double timedSort(Container &container)
	{
		clock_t start = clock();
		sort(container);
		clock_t end = clock();
		return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
	};

  private:
	template <typename Container> void sort(Container &container)
	{
		for (size_t i = 1; i < container.size(); i++)
		{
			int key(container[i]);
			int j(i - 1);

			while (j >= 0 && container[j] > key)
			{
				container[j + 1] = container[j];
				j--;
			}

			container[j + 1] = key;
		}
	};
};

#endif /* PMERGEME_HPP */
