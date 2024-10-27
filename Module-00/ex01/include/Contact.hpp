/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:15 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 19:24:16 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickname(std::string nickname);
	void setPhone(std::string phone);
	void setSecret(std::string secret);
	void displayDetails(void) const;

  private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone;
	std::string m_secret;
};

#endif /* CONTACT_HPP */
