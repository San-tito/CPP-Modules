/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:59:25 by sguzman           #+#    #+#             */
/*   Updated: 2024/10/16 18:39:01 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX 8
# define WIDTH 10
# define PROGRAM "phonebook"
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
	int count;
	Contact contacts[MAX];
	void display(void) const;
};

#endif /* PHONEBOOK_HPP */
