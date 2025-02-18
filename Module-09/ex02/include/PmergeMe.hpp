/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/18 13:04:34 by sguzman          ###   ########.fr       */
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

template <typename T> void printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << '\n';
};

class PmergeMe
{
  public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	template <typename T> double timedSort(T &container)
	{
		clock_t start = clock();
		sort(container);
		clock_t end = clock();
		return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
	};

  private:
	template <typename T> void sort(T &container, size_t pair_size = 1)
	{
		typedef typename T::iterator iterator;

		size_t num_pairs = container.size() / pair_size;
		if (num_pairs <= 1)
			return ;

		for (size_t i = 0; i < num_pairs * pair_size; i += (pair_size * 2))
		{
			iterator start(container.begin() + i);
			iterator mid(container.begin() + i + pair_size);
			iterator end(container.begin() + i + (pair_size * 2));
			if (end > container.end())
				continue ;
			T left(start, mid);
			T right(mid, end);

			// std::cout << "pair_size: " << pair_size << std::endl;
			// std::cout << "[ ";
			// for (iterator it = left.begin(); it != left.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << "]" << std::endl;
			// std::cout << "[ ";
			// for (iterator it = right.begin(); it != right.end(); ++it)
			// 	std::cout << *it << " ";
			// std::cout << "]" << std::endl;

			if (left.empty() == 0 && right.empty() == 0
				&& left.back() > right.back())
				std::swap_ranges(start, mid, mid);
		}

		sort(container, pair_size * 2);
		T main;
		T pend;

		bool first_iteration(true);
		for (size_t i = 0; i < container.size(); i += (pair_size * 2))
		{
			iterator start(container.begin() + i);
			iterator mid(container.begin() + i + pair_size);
			iterator end(container.begin() + i + (pair_size * 2));
			if (end > container.end())
			{
				pend.insert(pend.end(), start, container.end());
				continue ;
			}
			T b(start, mid);
			T a(mid, end);

			if (first_iteration)
			{
				main.insert(main.end(), b.begin(), b.end());
				main.insert(main.end(), a.begin(), a.end());
				first_iteration = false;
			}
			else
			{
				main.insert(main.end(), a.begin(), a.end());
				pend.insert(pend.end(), b.begin(), b.end());
			}
		}

		std::cout << "Main chain: ";
		printContainer(main);
		std::cout << "Pend chain: ";
		printContainer(pend);
	};
};

#endif /* PMERGEME_HPP */
