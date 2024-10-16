/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:25 by sguzman           #+#    #+#             */
/*   Updated: 2024/09/10 19:59:26 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX 8
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	int commandPrompt(void);

  private:
	Contact contacts_[MAX];
};
