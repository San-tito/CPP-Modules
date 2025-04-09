/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/07 13:08:51 by sguzman          ###   ########.fr       */
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
	double time_vector = TimedSort(vec_);
	double time_list = TimedSort(lst_);
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

template <typename Container>
void PmergeMe::Display(Container &container)
{
	for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}
template void PmergeMe::Display(std::vector<int> &);
template void PmergeMe::Display(std::list<int> &);

template <typename Container>
double PmergeMe::TimedSort(Container &container)
{
	clock_t start = clock();
	Sort(container);
	clock_t end = clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
template double PmergeMe::TimedSort(std::vector<int> &);
template double PmergeMe::TimedSort(std::list<int> &);

template <typename Container>
void PmergeMe::Sort(Container &container, size_t elem_size)
{
	typedef typename Container::iterator iterator;
	size_t num_pairs(container.size() / elem_size);
	if (num_pairs <= 1)
		return ;
	for(iterator start(container.begin()); start != container.end(); start += elem_size * 2)
	{
		iterator mid(start + elem_size);
		iterator end(start + elem_size * 2);
		if (end > container.end())
			break ;
		if(*mid > *end)
			std::swap_ranges(start, mid, mid);
	}
	Sort(container, elem_size * 2);
	Container main(container.begin(), container.begin() + elem_size * 2);
	Container pend;
	Container odd;
	for (iterator it(container.begin() + elem_size * 2); it != container.end(); it += elem_size * 2)
	{
		pend.insert(pend.end(), it, it + elem_size);
		if(*(it + elem_size * 2) > container.end())
			break ;
		main.insert(main.end(), it + elem_size, it + elem_size * 2);
	}
	std::cout << "Main: ";
	Display(main);
	std::cout << "Pend: ";
	Display(pend);
	std::cout << "Odd: ";
	Display(odd);
}
template void PmergeMe::Sort(std::vector<int> &, size_t);
template void PmergeMe::Sort(std::list<int> &, size_t);


