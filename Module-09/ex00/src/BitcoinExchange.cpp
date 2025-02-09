/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/02/09 17:53:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open db file");
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date("");
		float price(0);
		if (std::getline(iss, date, ',') && iss >> price)
			data_[parseDate(date)] = price;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	data_ = other.data_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	data_ = other.data_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

time_t BitcoinExchange::parseDate(const std::string &date) const
{
	std::tm tm;
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		throw std::runtime_error("Error: invalid date format => " + date);
	return (std::mktime(&tm));
}

std::string BitcoinExchange::computeLine(const std::string &line) const
{
	std::istringstream iss(line);
	std::string date("");
	float value(0);
	if (std::getline(iss, date, '|') && iss >> value)
	{
		if (value < 0 || value > 1000)
			throw std::runtime_error("Error: invalid value => "
				+ static_cast<std::ostringstream &>(std::ostringstream() << value).str());
		time_t t(parseDate(date));
		std::map<time_t, float>::const_iterator it = data_.lower_bound(t);
		if (it == data_.end() || it->first != t)
		{
			if (it == data_.begin())
				throw std::runtime_error("Error: no data for date => " + date);
			--it;
		}
		std::ostringstream oss;
		oss << date << " => " << value << " = " << (value * it->second);
		return (oss.str());
	}
	throw std::runtime_error("Error: invalid input format => " + line);
}
