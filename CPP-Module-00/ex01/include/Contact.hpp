/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:15 by sguzman           #+#    #+#             */
/*   Updated: 2024/09/10 19:59:16 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
  public:
	Contact(void);
	~Contact(void);

  private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_;
	std::string secret_;
};
