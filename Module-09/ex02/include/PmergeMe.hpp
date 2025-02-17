/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/17 18:42:31 by sguzman          ###   ########.fr       */
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

	template <typename T> double timedSort(T &container)
	{
		clock_t start = clock();
		sort(container);
		clock_t end = clock();
		return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
	};

  private:
	template <typename T> T &merge(T &left, T &right)
	{
		if (left.back() < right.back())
		{
			left.insert(left.end(), right.begin(), right.end());
			return (left);
		}
		else
		{
			right.insert(right.end(), left.begin(), left.end());
			return (right);
		}
	};
	template <typename T> void sort(T &seq)
	{
		if (seq.size() <= 1)
			return ;
		T left(seq.begin(), seq.begin() + seq.size() / 2);
		T right(seq.begin() + seq.size() / 2, seq.end());
		sort(left);
		sort(right);
		seq = merge(left, right);
	};
};

#endif /* PMERGEME_HPP */
