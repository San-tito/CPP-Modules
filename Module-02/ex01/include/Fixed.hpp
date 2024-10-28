/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:58:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/28 09:02:44 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# define FRACTIONAL_BITS 8

class Fixed
{
  public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int m_value;
	static const int m_fractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
