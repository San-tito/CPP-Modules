/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/18 15:49:36 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
	size_t jacobsthal(size_t n);
	template <typename T> void sort(T &seq, size_t pair_size = 1)
	{
		typedef typename T::iterator iterator;

		size_t num_pairs = seq.size() / pair_size;
		if (num_pairs <= 1)
			return ;

		for (size_t i = 0; i < num_pairs * pair_size; i += (pair_size * 2))
		{
			iterator start(seq.begin() + i);
			iterator mid(seq.begin() + i + pair_size);
			iterator end(seq.begin() + i + (pair_size * 2));
			if (end > seq.end())
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

			if (!left.empty() && !right.empty() && left.back() > right.back())
				std::swap_ranges(start, mid, mid);
		}

		sort(seq, pair_size * 2);
		T main;
		T pend;

		main.insert(main.end(), seq.begin(), seq.begin() + pair_size);
		main.insert(main.end(), seq.begin() + pair_size, seq.begin()
			+ (pair_size * 2));
		for (size_t i = (pair_size * 2); i < seq.size(); i += (pair_size * 2))
		{
			iterator start(seq.begin() + i);
			iterator mid(seq.begin() + i + pair_size);
			iterator end(seq.begin() + i + (pair_size * 2));
			if (end > seq.end())
			{
				pend.insert(pend.end(), start, seq.end());
				continue ;
			}
			T b(start, mid);
			T a(mid, end);
			main.insert(main.end(), a.begin(), a.end());
			pend.insert(pend.end(), b.begin(), b.end());
		}

		std::cout << "Main chain: ";
		printContainer(main);
		std::cout << "Pend chain: ";
		printContainer(pend);

		size_t previous(jacobsthal(1));
		for (size_t k = 2;; k++)
		{
			size_t current(jacobsthal(k));
			if (current - previous > pend.size())
				break ;
			std::cout << "prev: " << previous << " curr: " << current << '\n';
			previous = current;
		}
	};
};

#endif /* PMERGEME_HPP */
