/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:25 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/27 18:55:33 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8
# define WIDTH_COLUMN 10
# define PROMPT "┌─[phoneBook]\n└─$ "
# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <limits>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void) const;

  private:
	int m_count;
	Contact m_contacts[MAX_CONTACTS];
	void display(void) const;
};

#endif /* PHONEBOOK_HPP */
