/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/11/03 19:28:11 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>

class ScalarConverter
{
  public:
	static void convert(const std::string &literal);

  private:
    static void convertToChar(double value, std::string &str);
    static void convertToInt(double value, std::string &str);
    static void convertToFloat(double value, std::string &str);
    static void convertToDouble(double value, std::string &str);
};

#endif /* SCALARCONVERTER_HPP */
