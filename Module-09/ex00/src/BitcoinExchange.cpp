/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/25 11:56:52 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date("");
		float price(0);
		if (std::getline(iss, date, ',') && iss >> price)
			data_[parseDate(trim(date))] = price;
	}
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

std::string BitcoinExchange::trim(const std::string &str) const
{
	std::string::const_iterator start(str.begin());
	while (start != str.end() && std::isspace(*start))
		++start;
	std::string::const_iterator end(str.end());
	do
	{
		--end;
	} while (std::distance(start, end) > 0 && std::isspace(*end));
	return (std::string(start, end + 1));
}

time_t BitcoinExchange::parseDate(const std::string &date) const
{
	std::tm tm = {};
	const char *res(strptime(date.c_str(), "%Y-%m-%d", &tm));
	if (res == NULL || *res != '\0')
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
		date = trim(date);
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
