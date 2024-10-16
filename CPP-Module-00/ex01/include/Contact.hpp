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

# include <string>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	std::string getFirstName() const;
	void setFirstName(std::string first_name);
	std::string getLastName() const;
	void setLastName(std::string last_name);
	std::string getNickname() const;
	void setNickname(std::string nickname);
	std::string getPhone() const;
	void setPhone(std::string phone);
	std::string getSecret() const;
	void setSecret(std::string secret);

  private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_;
	std::string secret_;
};

#endif /* CONTACT_HPP */
