/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2025/04/25 11:56:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
  public:
	BitcoinExchange(std::ifstream &file);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);
	std::string computeLine(const std::string &line) const;

  private:
	std::map<time_t, float> data_;
	time_t parseDate(const std::string &date) const;
	std::string trim(const std::string &str) const;
};

#endif /* BITCOINEXCHANGE_HPP */
