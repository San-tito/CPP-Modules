/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/14 01:22:28 by sguzman          ###   ########.fr       */
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
	std::vector<int> sorted_vec(vec_);
	std::sort(sorted_vec.begin(), sorted_vec.end());
	if (sorted_vec != vec_)
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
		return (0);
	if (n == 1)
		return (1);
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

template <typename T> T PmergeMe::BinarySearch(T low, T high, size_t e,
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
	return (low);
}
template std::vector<int>::iterator PmergeMe::BinarySearch(std::vector<int>::iterator,
	std::vector<int>::iterator, size_t, int);
template std::deque<int>::iterator PmergeMe::BinarySearch(std::deque<int>::iterator,
	std::deque<int>::iterator, size_t, int);

template <typename T> void PmergeMe::Sort(T &container, size_t elem_size)
{
	typedef typename T::iterator iterator;
	size_t num_elems(container.size() / elem_size);
	if (num_elems <= 1)
		return ;
	for (iterator start(container.begin()); start + elem_size
		* 2 <= container.end(); start += elem_size * 2)
	{
		iterator mid(start + elem_size);
		iterator end(start + elem_size * 2);
		T left(start, mid);
		T right(mid, end);
		if (left.back() > right.back())
			std::swap_ranges(start, mid, mid);
	}
	Sort(container, elem_size * 2);
	T main(container.begin(), container.begin() + elem_size * 2);
	T pend(0);
	T odd(0);
	iterator it(container.begin() + elem_size * 2);
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
	// for (size_t jc = 3;; jc++)
	// {
	// 	size_t diff(Jacobsthal(jc) - Jacobsthal(jc - 1));
	// 	if (diff > pend.size() / elem_size)
	// 		diff = pend.size();
	// 	while (diff)
	// 	{
	// 		T element(pend.begin(), pend.begin() + elem_size);
	// 		iterator low(main.begin() + elem_size - 1);
	// 		iterator high(main.end() - 1);
	// 		iterator search(BinarySearch(low, high, elem_size, element.back()));
	// 		main.insert(search, element.begin(), element.end());
	// 		pend.erase(pend.begin(), pend.begin() + elem_size);
	// 		diff--;
	// 	}
	// }
	it = pend.begin();
	for (; it + elem_size <= pend.end(); it += elem_size)
	{
		T element(it, it + elem_size);
		iterator low(main.begin() + elem_size - 1);
		iterator high(main.end() - 1);
		iterator search(BinarySearch(low, high, elem_size, element.back()));
		main.insert(search - elem_size + 1, element.begin(), element.end());
	}
	main.insert(main.end(), odd.begin(), odd.end());
	container = main;
}
template void PmergeMe::Sort(std::vector<int> &, size_t);
template void PmergeMe::Sort(std::deque<int> &, size_t);
