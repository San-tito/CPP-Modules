/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:15 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/16 19:33:50 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	std::string getFirstName(void) const;
	void setFirstName(std::string first_name);
	std::string getLastName(void) const;
	void setLastName(std::string last_name);
	std::string getNickname(void) const;
	void setNickname(std::string nickname);
	std::string getPhone(void) const;
	void setPhone(std::string phone);
	std::string getSecret(void) const;
	void setSecret(std::string secret);
	void displayDetails(void) const;

  private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_;
	std::string secret_;
};

#endif /* CONTACT_HPP */
