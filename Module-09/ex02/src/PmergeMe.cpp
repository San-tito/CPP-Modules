/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/23 12:37:47 by sguzman          ###   ########.fr       */
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
		deq_.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_(other.vec_), deq_(other.deq_)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	vec_ = other.vec_;
	deq_ = other.deq_;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	std::vector<int> sorted(vec_);
	std::sort(sorted.begin(), sorted.end());
	if (sorted != vec_)
		std::cerr << "Error: is not sorted\n";
}

void PmergeMe::Run(void)
{
	std::cout << "Before: ";
	Display(vec_);
	double time_vector(TimedSort(vec_));
	double time_deque(TimedSort(deq_));
	std::cout << "After: ";
	Display(vec_);
	std::cout << "Time to process a range of " << vec_.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << time_vector << " seconds.\n";
	std::cout << "Time to process a range of " << deq_.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << time_deque << " seconds.\n";
}

size_t PmergeMe::Jacobsthal(size_t n)
{
	if (n == 0)
		return (n);
	if (n == 1)
		return (n);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}

template <typename T> void PmergeMe::Display(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}
template void PmergeMe::Display(std::vector<int> &);
template void PmergeMe::Display(std::deque<int> &);

template <typename T> double PmergeMe::TimedSort(T &container)
{
	clock_t start(clock());
	Sort(container);
	clock_t end(clock());
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC);
}
template double PmergeMe::TimedSort(std::vector<int> &);
template double PmergeMe::TimedSort(std::deque<int> &);

template <typename T> T PmergeMe::BinarySearch(T &low, T &high, size_t e,
	int value)
{
	while (low <= high)
	{
		size_t distance(high - low);
		size_t num_elems(distance / e + 1);
		T mid(low + ((num_elems / 2) * e));
		if (*mid < value)
			low = mid + e;
		else
			high = mid - e;
	}
	return (low - e + 1);
}
template std::vector<int>::iterator PmergeMe::BinarySearch(std::vector<int>::iterator &,
	std::vector<int>::iterator &, size_t, int);
template std::deque<int>::iterator PmergeMe::BinarySearch(std::deque<int>::iterator &,
	std::deque<int>::iterator &, size_t, int);

template <typename T> void PmergeMe::BinaryInsert(T &elem, T &container,
	size_t e, size_t index, size_t &inserted)
{
	typedef typename T::iterator iterator;
	iterator low(container.begin() + e - 1);
	iterator high(container.end() - 1);
	size_t limit((index + inserted + 2) * e);
	if (limit < container.size())
		high = container.begin() + limit - 1;
	iterator spot(BinarySearch(low, high, e, elem.back()));
	container.insert(spot, elem.begin(), elem.end());
	inserted++;
}
template void PmergeMe::BinaryInsert(std::vector<int> &, std::vector<int> &,
	size_t, size_t, size_t &);
template void PmergeMe::BinaryInsert(std::deque<int> &, std::deque<int> &,
	size_t, size_t, size_t &);

template <typename T> void PmergeMe::Sort(T &container, size_t elem_size)
{
	typedef typename T::iterator iterator;
	size_t num_elems(container.size() / elem_size);
	if (num_elems <= 1)
		return ;
	iterator it(container.begin());
	for (; it + elem_size * 2 <= container.end(); it += elem_size * 2)
	{
		iterator mid(it + elem_size);
		iterator end(it + elem_size * 2);
		T left(it, mid);
		T right(mid, end);
		if (left.back() > right.back())
			std::swap_ranges(it, mid, mid);
	}
	Sort(container, elem_size * 2);
	T main(container.begin(), container.begin() + elem_size * 2);
	T pend(0);
	T odd(0);
	it = container.begin() + elem_size * 2;
	for (; it + elem_size <= container.end(); it += elem_size)
	{
		pend.insert(pend.end(), it, it + elem_size);
		if (it + elem_size * 2 > container.end())
			continue ;
		main.insert(main.end(), it + elem_size, it + elem_size * 2);
		it += elem_size;
	}
	if (it < container.end())
		odd.insert(odd.end(), it, container.end());
	size_t inserted(0);
	size_t prev(Jacobsthal(0));
	for (size_t jc = 1;; jc++)
	{
		size_t curr(Jacobsthal(jc));
		size_t diff(curr - prev);
		if (curr > pend.size() / elem_size)
			break ;
		for (size_t i = 0; i < diff; i++)
		{
			size_t index(curr - i - 1);
			iterator start(pend.begin() + index * elem_size);
			iterator end(start + elem_size);
			T element(start, end);
			BinaryInsert(element, main, elem_size, index, inserted);
		}
		prev = curr;
	}
	it = pend.begin() + (inserted * elem_size);
	for (; it + elem_size <= pend.end(); it += elem_size)
	{
		T element(it, it + elem_size);
		size_t index((it - pend.begin()) / elem_size);
		BinaryInsert(element, main, elem_size, index, inserted);
	}
	main.insert(main.end(), odd.begin(), odd.end());
	container = main;
}
template void PmergeMe::Sort(std::vector<int> &, size_t);
template void PmergeMe::Sort(std::deque<int> &, size_t);
