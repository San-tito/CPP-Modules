/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/07 13:03:28 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integers>\n";
		exit(1);
	}
	for (int i = 1; i < argc; i++)
	{
		int num(0);
		std::istringstream iss(argv[i]);
		if ((!(iss >> num)) || (num < 0) || std::find(vec_.begin(), vec_.end(),
				num) != vec_.end())
		{
			std::cerr << "Error: invalid argument '" << argv[i] << "'\n";
			exit(1);
		}
		vec_.push_back(num);
		lst_.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_(other.vec_), lst_(other.lst_)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	vec_ = other.vec_;
	lst_ = other.lst_;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}

void PmergeMe::Run(void)
{
	std::cout << "Before: ";
	Display(vec_);
	double time_vector(TimedSort(vec_));
	double time_list(TimedSort(lst_));
	std::cout << "After: ";
	Display(vec_);
	std::cout << "Time to process a range of " << vec_.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << time_vector << " seconds.\n";
	std::cout << "Time to process a range of " << lst_.size() << " elements with std::list: " << std::fixed << std::setprecision(5) << time_list << " seconds.\n";
}

size_t PmergeMe::Jacobsthal(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}

void PmergeMe::Display(std::vector<int> &vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

void PmergeMe::Display(std::list<int> &lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

double PmergeMe::TimedSort(std::vector<int> &vec)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	Sort(vec);
	end = clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

double PmergeMe::TimedSort(std::list<int> &lst)
{
	clock_t start(clock());
	Sort(lst);
	clock_t end(clock());
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

void PmergeMe::Sort(std::vector<int> &vec, size_t pair_size)
{
	size_t num_pairs(vec.size() / pair_size);
	if (num_pairs <= 1)
		return ;
	for (size_t i = 0; i < vec.size(); i += pair_size * 2)
	{
		std::vector<int>::iterator start(vec.begin() + i);
		std::vector<int>::iterator mid(vec.begin() + i + pair_size);
		std::vector<int>::iterator end(vec.begin() + i + pair_size * 2);
		if (end > vec.end())
			continue ;
		std::vector<int> left(start, mid);
		std::vector<int> right(mid, end);
		if (left.back() > right.back())
			std::swap_ranges(start, mid, mid);
	}
	Sort(vec, pair_size * 2);
	std::vector<int> main(vec.begin(), vec.begin() + pair_size * 2);
	std::vector<int> pend;
	std::vector<int> odd;
	for (size_t i = pair_size * 2; i + pair_size < vec.size(); i += pair_size
		* 2)
	{
		std::vector<int> b(vec.begin() + i, vec.begin() + i + pair_size);
		pend.insert(pend.end(), b.begin(), b.end());
		if (i + pair_size * 2 > vec.size())
		{
			odd.insert(odd.end(), vec.begin() + i + pair_size, vec.end());
			break ;
		}
		std::vector<int> a(vec.begin() + i + pair_size, vec.begin() + i
			+ pair_size * 2);
		main.insert(main.end(), a.begin(), a.end());
	}
	std::cout << "Main: ";
	Display(main);
	std::cout << "Pend: ";
	Display(pend);
	std::cout << "Odd: ";
	Display(odd);
}

void PmergeMe::Sort(std::list<int> &lst, size_t pair_size)
{
	static_cast<void>(lst);
	static_cast<void>(pair_size);
}
