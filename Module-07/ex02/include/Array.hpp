/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/01/21 09:08:01 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <iostream>
# include <stdexcept>

template <typename T> class Array
{
  public:
	Array(void) : size_(0), data_(NULL)
	{
	}
	Array(unsigned int n) : size_(n), data_(new T[n])
	{
	}
	Array(const Array &other) : size_(other.size_)
	{
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = other.data_[i];
	}
	Array &operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		delete[] data_;
		size_ = other.size_;
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = other.data_[i];
		return (*this);
	}

	~Array(void)
	{
		delete[] data_;
	}

	T &operator[](unsigned int index)
	{
		if (index >= size_)
			throw std::out_of_range("Index out of range");
		return (data_[index]);
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= size_)
			throw std::out_of_range("Index out of range");
		return (data_[index]);
	}
	unsigned int size() const
	{
		return (size_);
	}

  private:
	unsigned int size_;
	T *data_;
};

#endif /* ARRAY_HPP */
